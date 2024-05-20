#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M;
int map[8][8];
int copy_map[8][8];
bool visited[64];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
struct Point
{
	int y, x;
};
vector<Point> space;
int answer = 0;

void input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 0)
			{
				space.push_back({ i, j });
			}
		}
	}
}

void bfs()
{
	queue<Point> q;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (copy_map[i][j] == 2)
			{
				q.push({ i, j });
			}
		}
	}

	while (!q.empty())
	{
		Point now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			Point next = { 0, };
			next.y = now.y + dy[i];
			next.x = now.x + dx[i];

			if (next.y < 0 || next.x < 0 || next.y >= N || next.x >= M) continue;
			if (copy_map[next.y][next.x] == 0)
			{
				copy_map[next.y][next.x] = 2;
				q.push(next);
			}
		}
	}

	int cnt = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (copy_map[i][j] == 0)
			{
				cnt++;
			}
		}
	}

	answer = max(cnt, answer);
}

void make_wall(int level, int idx)
{
	if (level == 3)
	{
		memcpy(copy_map, map, sizeof(map));
		int cnt = 0;
		for (int i = 0; i < space.size(); i++)
		{
			if (cnt == 3) break;
			if (visited[i])
			{
				int y = space[i].y;
				int x = space[i].x;
				copy_map[y][x] = 1;
				cnt++;
			}
		}

		bfs();
		return;
	}

	for (int i = 0; i < space.size(); i++)
	{
		if (visited[i]) continue;
		visited[i] = true;
		make_wall(level + 1, i);
		visited[i] = false;
	}
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	input();
	make_wall(0, 0);

	cout << answer << endl;
}