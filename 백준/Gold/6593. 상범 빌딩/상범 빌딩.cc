#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

int L, R, C;

struct Point
{
	int z, y, x;
};

int dz[2] = {-1, 1};
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

Point st, en;

char building[30][30][30];
int visited[30][30][30];

void input()
{
	for (int floor = 0; floor < L; floor++)
	{
		for (int row = 0; row < R; row++)
		{
			for (int col = 0; col < C; col++)
			{
				cin >> building[floor][row][col];

				if (building[floor][row][col] == 'S')
				{
					st.z = floor;
					st.y = row;
					st.x = col;
				}
				else if (building[floor][row][col] == 'E')
				{
					en.z = floor;
					en.y = row;
					en.x = col;
				}
			}
		}
	}
}

void bfs()
{
	memset(visited, -1, sizeof(visited));

	queue<Point> q;
	q.push(st);
	visited[st.z][st.y][st.x] = 0;

	while (!q.empty())
	{
		Point now = q.front();
		q.pop();

		// 상하
		for (int i = 0; i < 2; i++)
		{
			Point next = { now.z + dz[i], now.y, now.x };

			if (next.z < 0 || next.z >= L) continue;
			if (building[next.z][next.y][next.x] == '#') continue;
			if (visited[next.z][next.y][next.x] != -1) continue;

			visited[next.z][next.y][next.x] = visited[now.z][now.y][now.x] + 1;

			q.push(next);
		}
		// 동서남북
		for (int i = 0; i < 4; i++)
		{
			Point next = { now.z, now.y + dy[i], now.x + dx[i] };

			if (next.y < 0 || next.y >= R || next.x < 0 || next.x >= C) continue;
			if (building[next.z][next.y][next.x] == '#') continue;
			if (visited[next.z][next.y][next.x] != -1) continue;

			visited[next.z][next.y][next.x] = visited[now.z][now.y][now.x] + 1;

			q.push(next);
		}
	}
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	
	while (true)
	{
		cin >> L >> R >> C;

		if (L == 0 && R == 0 && C == 0)
		{
			return 0;
		}

		input();

		bfs();

		if (visited[en.z][en.y][en.x] != -1)
		{
			cout << "Escaped in " << visited[en.z][en.y][en.x] << " minute(s)." << endl;
		}
		else
		{
			cout << "Trapped!" << endl;
		}
	}
}