#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

int N, M;
int map[101][101];
int visited[101][101] = { 0, };
int arr[101][101] = { 0, };
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
struct Point
{
	int y, x;
};

void input()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < M; j++)
		{
			map[i][j + 1] = temp[j] - 48;
		}
	}
}

void bfs(Point st)
{
	queue<Point> q;
	q.push(st);
	visited[st.y][st.x] = 1;
	arr[st.y][st.x] = 1;

	while (!q.empty())
	{
		Point now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			Point next;
			next.y = now.y + dy[i];
			next.x = now.x + dx[i];

			if (next.y < 1 || next.x < 1 || next.y > 100 || next.x > 100) continue;
			if (map[next.y][next.x] == 0) continue;
			if (visited[next.y][next.x] == 1) continue;

			arr[next.y][next.x] = arr[now.y][now.x] + 1;
			visited[next.y][next.x] = 1;

			if (next.y == N && next.x == M) break;
			q.push(next);
		}
	}
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	input();

	bfs({1, 1});

	cout << arr[N][M];
}