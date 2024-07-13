#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int M, N, K;;
int map[51][51];
int visited[51][51];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

struct Point
{
	int y, x;
};

void init()
{
	memset(map, 0, sizeof(map));
	memset(visited, 0, sizeof(visited));
}

void input()
{
	cin >> M >> N >> K;
	for (int i = 0; i < K; i++)
	{
		int x, y;
		cin >> x >> y;
		map[y][x] = 1;
	}
}

void bfs(Point st, int num)
{
	queue<Point> q;
	q.push(st);
	visited[st.y][st.x] = 1;
	map[st.y][st.x] = num;

	while (!q.empty())
	{
		Point now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			Point next;
			next.y = now.y + dy[i];
			next.x = now.x + dx[i];

			if (map[next.y][next.x] == 0) continue;
			if (next.y < 0 || next.x < 0 || next.y >= N || next.x >= M) continue;
			if (visited[next.y][next.x] == 1) continue;

			visited[next.y][next.x] = 1;
			map[next.y][next.x] = num;
			
			q.push(next);
		}
	}
}

void solution()
{
	int num = 2;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 1)
			{
				bfs({ i, j }, num);
				num++;
			}
		}
	}

	cout << num - 2 << endl;
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		init();
		input();

		solution();
	}
}