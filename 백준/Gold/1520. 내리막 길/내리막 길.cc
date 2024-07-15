#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int M, N;
int H;
int map[501][501];
int dp[501][501] = { 0, };
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
struct Point
{
	int y, x;
};


void input()
{
	cin >> M >> N;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			dp[i][j] = -1;
		}
	}
}

int dfs(Point now)
{
	if (now.y == M - 1 && now.x == N - 1) return 1;
	if (dp[now.y][now.x] != -1) return dp[now.y][now.x];

	dp[now.y][now.x] = 0;

	for (int i = 0; i < 4; i++)
	{
		Point next;
		next.y = now.y + dy[i];
		next.x = now.x + dx[i];

		if (next.y < 0 || next.x < 0 || next.y >= M || next.x >= N) continue;

		if (map[next.y][next.x] < map[now.y][now.x])
		{
			dp[now.y][now.x] += dfs(next);
		}
	}

	return dp[now.y][now.x];
}

void solution()
{
	H = dfs({0, 0});
	cout << H << endl;
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	input();
	
	solution();
}