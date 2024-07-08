#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

int N;
int map[100][100];
long long dp[100][100] = { 0, };
int dy[2] = { 0, 1 };
int dx[2] = { 1, 0 };
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
			cin >> map[i][j];
		}
	}
}

void solution()
{
	dp[0][0] = 1;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (dp[i][j] == 0 || (i == N - 1 && j == N - 1)) continue;

			long long jump = map[i][j];
			long long down = i + jump;
			long long right = j + jump;

			if (down < N)
			{
				dp[down][j] += dp[i][j];
			}
			if (right < N)
			{
				dp[i][right] += dp[i][j];
			}
		}
	}
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	input();

	solution();

	cout << dp[N - 1][N - 1];
}