#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

char map[8][8];
bool visited[9][8][8];
int dy[9] = { -1, -1, 0, 1, 1, 1, 0, -1, 0 };
int dx[9] = { 0, 1, 1, 1, 0, -1, -1, -1, 0 };

struct Point
{
	int time;
	int y, x;
};

void input()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cin >> map[i][j];
		}
	}
}

int bfs()
{
	queue<Point> q;
	q.push({ 0, 7, 0 });
	visited[0][7][0] = true;

	while (!q.empty())
	{
		Point now = q.front();
		q.pop();

		if (now.y == 0) return 1;

		for (int i = 0; i < 9; i++)
		{
			Point next;
			next.y = now.y + dy[i];
			next.x = now.x + dx[i];
			next.time = now.time + 1;

			if (next.time >= 8) return 1;

			if (next.y < 0 || next.x < 0 || next.y >= 8 || next.x >= 8) continue;
			if (next.y - now.time >= 0 && map[next.y - now.time][next.x] == '#') continue;
			if (next.y - now.time - 1 >= 0 && map[next.y - now.time - 1][next.x] == '#') continue;
			if (visited[next.time][next.y][next.x] == false)
			{
				visited[next.time][next.y][next.x] = true;
				q.push(next);
			}
		}
	}

	return 0;
}

void solution()
{
	int ans = bfs();

	cout << ans;
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	input();

	solution();
}