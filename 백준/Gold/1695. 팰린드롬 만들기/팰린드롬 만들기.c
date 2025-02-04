#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MIN(x, y) x < y ? x : y

int N;
int arr[5001];
int dp[5001][5001];

void input()
{
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
}

int back(int s, int e)
{
	if (s >= e) return 0;

	if (dp[s][e] != -1)
	{
		return dp[s][e];
	}

	int cnt = 0;

	if (arr[s] == arr[e])
	{
		cnt = back(s + 1, e - 1);
	}
	else
	{
		cnt = MIN(back(s, e - 1) + 1, back(s + 1, e) + 1);
	}

	return dp[s][e] = cnt;
}

void solution()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			dp[i][j] = -1;
		}
	}

	int ans = back(0, N - 1);

	printf("%d", ans);
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	input();

	solution();
}