#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int N;
int map[20][20];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
struct Point
{
	int y, x;
	int dist;
};
Point player = { 0, };
int level = 2;
int timer = 0;
struct cmp
{
	bool operator() (Point a, Point b)
	{
		if (a.dist == b.dist)
		{
			if (a.y == b.y)
			{
				return a.x > b.x;
			}
			return a.y > b.y;
		}
		return a.dist > b.dist;
	}
};

void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 9)
			{
				map[i][j] = 0;
				player = { i, j, 0 };
			}
		}
	}
}

int bfs()
{
	int visited[20][20];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			visited[i][j] = 21e8;
		}
	}
	priority_queue<Point, vector<Point>, cmp> pq;
	pq.push(player);
	visited[player.y][player.x] = 0;

	while (!pq.empty())
	{
		Point now = pq.top();
		pq.pop();

		if (map[now.y][now.x] != 0 && map[now.y][now.x] < level) // 몬스터 잡았다
		{
			map[now.y][now.x] = 0;
			player = { now };
			return 1;
		}

		for (int i = 0; i < 4; i++)
		{
			Point next = { 0, };
			next.y = now.y + dy[i];
			next.x = now.x + dx[i];
			next.dist = visited[now.y][now.x] + 1;

			if (next.y < 0 || next.x < 0 || next.y >= N || next.x >= N) continue; // 맵 벗어나면 continue
			if (map[next.y][next.x] > level) continue; // 플레이어보다 레벨이 높으면 continue;
			if (visited[next.y][next.x] <= next.dist) continue; // 최소거리가 아니면 continue;

			visited[next.y][next.x] = next.dist;
			pq.push(next);
		}
	}
	return 0;
}

int main() {
	input();

	int exp = 0;
	while (bfs())
	{
		exp++;
		timer += player.dist;

		if (exp == level)
		{
			exp = 0;
			level++;
		}
	}

	cout << timer;
}