#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int maxlen = 0;
int map[50][50];
int visited[50][50] = { 0, };
int arr[50][50] = { 0, };
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1 ,1 };
struct Point
{
	int y, x;
};

void input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			char temp;
			cin >> temp;

			if (temp == 'W')
			{
				map[i][j] = 0;
			}
			else if (temp == 'L')
			{
				map[i][j] = 1;
			}
		}
	}
}

int bfs(Point st)
{
	queue<Point> q;
	memset(visited, 0, sizeof(visited));
	memset(arr, 0, sizeof(arr));
	q.push(st);
	visited[st.y][st.x] = 1;
	Point now;

	while (!q.empty())
	{
		now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			Point next;
			next.y = now.y + dy[i];
			next.x = now.x + dx[i];

			if (next.y < 0 || next.x < 0 || next.y > N || next.x > M) continue;
			if (visited[next.y][next.x] == 1) continue;
			if (map[next.y][next.x] == 0) continue;

			visited[next.y][next.x] = 1;
			arr[next.y][next.x] = arr[now.y][now.x] + 1;
			q.push(next);
		}
	}

	return arr[now.y][now.x];
}
void solution()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (i == 3 && j == 0)
			{
				int de = -1;
			}
			if (map[i][j] == 1)
			{
				int len = bfs({i, j});
				maxlen = max(len, maxlen);
			}
		}
	}
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	input();

	solution();

	cout << maxlen;
}