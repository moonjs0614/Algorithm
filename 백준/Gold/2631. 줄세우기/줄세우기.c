#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX(x, y) x > y ? x : y
#define MIN(x, y) x < y ? x : y

int N;
int arr[201];
int dp[201];
int max_val = 0;
int min_num = 10000000;

void input()
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &arr[i]);
		min_num = MIN(min_num, arr[i]);
	}
}

void solution()
{
	for (int i = 1; i <= N; i++)
	{
		dp[i] = 1;

		for (int j = 1; j <= i; j++)
		{
			if (arr[j] < arr[i] && dp[i] <= dp[j])
			{
				dp[i] += 1;
			}
		}
		max_val = MAX(max_val, dp[i]);
	}

	printf("%d", N - max_val);
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	input();

	solution();
}