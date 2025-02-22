#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int M, N, H;
int box[100][100][100];
int visited[100][100][100];
int dz[2] = { -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int ripe_cnt = 0;
int unripe_cnt = 0;
int max_day = 0;

struct Point
{
	int z, y, x;
};

vector<Point> v;

void input()
{
	cin >> M >> N >> H;

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				cin >> box[i][j][k];

				if (box[i][j][k] == 1)
				{
					ripe_cnt++;
					v.push_back({ i, j ,k });
				}
				else if (box[i][j][k] == 0)
				{
					unripe_cnt++;
				}
			}
		}
	}
}

void bfs()
{
	queue<Point> q;
	for (int i = 0; i < ripe_cnt; i++)
	{
		q.push(v[i]);
		visited[v[i].z][v[i].y][v[i].x] = 0;
	}

	while (!q.empty())
	{
		Point now = q.front();
		q.pop();

		// 상하
		if (H > 1)
		{
			for (int i = 0; i < 2; i++)
			{
				Point next = { now.z + dz[i], now.y, now.x };

				if (next.z < 0 || next.z >= H) continue;
				if (visited[next.z][next.y][next.x] != -1) continue;
				if (box[next.z][next.y][next.x] != 0) continue;

				visited[next.z][next.y][next.x] = visited[now.z][now.y][now.x] + 1;
				box[next.z][next.y][next.x] = 1;
				unripe_cnt--;

				max_day = max(max_day, visited[next.z][next.y][next.x]);

				q.push(next);
			}
		}

		// 동서남북
		for (int i = 0; i < 4; i++)
		{
			Point next = { now.z, now.y + dy[i], now.x + dx[i] };

			if (next.y < 0 || next.y >= N || next.x < 0 || next.x >= M) continue;
			if (visited[next.z][next.y][next.x] != -1) continue;
			if (box[next.z][next.y][next.x] == -1) continue;

			visited[next.z][next.y][next.x] = visited[now.z][now.y][now.x] + 1;
			box[next.z][next.y][next.x] = 1;
			unripe_cnt--;

			max_day = max(max_day, visited[next.z][next.y][next.x]);

			q.push(next);
		}
	}
}

void solution()
{
	// 시작부터 다 익어있는 경우
	if (unripe_cnt == 0)
	{
		cout << 0;
		return;
	}

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				visited[i][j][k] = -1;
			}
		}
	}

	bfs();

	if (unripe_cnt > 0)
	{
		cout << -1;
	}
	else
	{
		cout << max_day;
	}
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	input();
	solution();
}