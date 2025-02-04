#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX(x, y) x > y ? x : y

int N;
int train[50001];
int sub;
int dp[50001][4];

void input()
{
	scanf("%d", &N);
	
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &train[i]);
	}

	scanf("%d", &sub);
}

void solution()
{
	// 초기값 설정
	for (int i = sub; i <= N; i++)
	{
		for (int j = i - sub + 1; j <= i; j++)
		{
			dp[i][0] += train[j];
		}
	}

	dp[sub][1] = dp[sub][0];
	dp[sub][2] = dp[sub][3] = 0;

	for (int i = sub + 1; i <= N; i++)
	{
		// 기관차 1대
		dp[i][1] = MAX(dp[i][0], dp[i - 1][1]);

		// 기관차 2대
		if (sub * 2 <= i)
		{
			dp[i][2] = MAX(dp[i][0] + dp[i - sub][1], dp[i - 1][2]);
		}

		// 기관차 3대
		if (sub * 3 <= i)
		{
			dp[i][3] = MAX(dp[i][0] + dp[i - sub][2], dp[i - 1][3]);
		}
	}

	printf("%d", dp[N][3]);
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	input();

	solution();
}