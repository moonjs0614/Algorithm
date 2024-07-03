#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

int N, M;
int map[1001][1001];
int dp[1001][1001];

void input()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> map[i][j];
		}
	}
}

void solution()
{
	dp[1][1] = map[1][1];
	dp[1][2] = map[1][1] + map[1][2];
	dp[2][1] = map[1][1] + map[2][1];

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (i == 1 && j == 1) continue;
			if (i == 1 && j == 2) continue;
			if (i == 2 && j == 1) continue;

			int a = dp[i - 1][j] + map[i][j];
			int b = dp[i][j - 1] + map[i][j];
			int c = dp[i - 1][j - 1] + map[i][j];

			dp[i][j] = max(a, max(b, c));
		}
	}
}


int main() {
	//freopen("sample_input.txt", "r", stdin);
	input();

	solution();

	cout << dp[N][M];
}