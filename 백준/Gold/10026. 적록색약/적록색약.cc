#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

int N;
int map1[101][101] = { 0, };
int map2[101][101] = { 0, };
int cnt1 = 0;
int cnt2 = 0;
bool visited1[101][101] = { 0, };
bool visited2[101][101] = { 0, };
int dy[4] = { -1, 1, 0 ,0 };
int dx[4] = { 0, 0, -1, 1 };
struct Point
{
	int y, x;
};

void input()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			char c;
			cin >> c;
			
			if (c == 'R')
			{
				map1[i][j] = 1;
				map2[i][j] = 1;
			}
			else if (c == 'G')
			{
				map1[i][j] = 2;
				map2[i][j] = 1;
			}
			else if (c == 'B')
			{
				map1[i][j] = 3;
				map2[i][j] = 3;
			}
		}
	}
}

void bfs(Point st, int color, int map[101][101], bool visited[101][101])
{
	queue<Point> q;
	q.push(st);
	visited[st.y][st.x] = 1;
	map[st.y][st.x] = color + 100;

	while (!q.empty())
	{
		Point now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			Point next = { now.y + dy[i], now.x + dx[i] };

			if (next.y < 0 || next.x < 0 || next.y >= N || next.x >= N) continue;
			if (visited[next.y][next.x]) continue;
			if (map[next.y][next.x] != color) continue;

			visited[next.y][next.x] = true;
			map[next.y][next.x] = color + 100;

			q.push(next);
		}
	}
}

void solution()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			// map1
			if (map1[i][j] >= 1 && map1[i][j] <= 3 && !visited1[i][j])
			{
				bfs({ i, j }, map1[i][j], map1, visited1);
				cnt1++;
			}

			// map2
			if (map2[i][j] >= 1 && map2[i][j] <= 3 && !visited2[i][j])
			{
				bfs({ i, j }, map2[i][j], map2, visited2);
				cnt2++;
			}

		}
	}


	cout << cnt1 << " " << cnt2 << endl;
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	input();

	solution();
}