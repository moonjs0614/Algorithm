#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

int N;
int click = 0;
int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
vector<string> v;
struct Point
{
	int y, x;
};

void init()
{
	v.clear();
	click = 0;
}

void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		v.push_back(s);
	}
}

int search(int y, int x)
{
	int cnt = 0;
	for (int i = 0; i < 8; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
		
		if (v[ny][nx] == '*') cnt++;
	}

	return cnt;
}

void bfs(int y, int x)
{
	queue<Point> q;
	q.push({ y, x });
	v[y][x] = '*';

	while (!q.empty())
	{
		Point now = q.front();
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			Point next = { 0, };
			next.y = now.y + dy[i];
			next.x = now.x + dx[i];

			if (next.y < 0 || next.x < 0 || next.y >= N || next.x >= N) continue;

			if (v[next.y][next.x] == '0')
			{
				v[next.y][next.x] = '*';
				q.push(next);
			}
			else if (v[next.y][next.x] != '*')
			{
				v[next.y][next.x] = '*';
			}
		}
	}
}

void solution()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (v[i][j] == '.')
			{
				int nums = search(i, j);
				v[i][j] = nums + '0';
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (v[i][j] == '0')
			{
				click++;
				bfs(i, j);
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (v[i][j] != '*')
			{
				click++;
				v[i][j] = '*';
			}
		}
	}
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

		cout << "#" << tc << " " << click << endl;
	}
}