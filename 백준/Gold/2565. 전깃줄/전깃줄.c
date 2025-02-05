#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX(x, y) x > y ? x : y

int N;
int arr[501];
int dp[501];
int result, max_val, prev = 0;

void input()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		int a, b;

		scanf("%d %d", &a, &b);

		arr[a] = b;
	}
}

void solution()
{
	for (int i = 1; i <= 500; i++)
	{
		if (arr[i] != 0)
		{
			int max = 0;
			
			for (int j = 0; j < i; j++)
			{
				if (arr[i] > arr[j])
				{
					if (dp[j] > max)
					{
						max = dp[j];
					}
				}
			}
			dp[i] = max + 1;

			if (dp[i] > max_val)
			{
				prev = i;
			}

			result = MAX(result, dp[i]);
		}
	}

	printf("%d", N - result);
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	input();

	solution();
}