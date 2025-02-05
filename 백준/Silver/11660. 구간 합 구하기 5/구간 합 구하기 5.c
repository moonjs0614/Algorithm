#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX(x, y) x > y ? x : y

int N, M;
int arr[1025][1025];
long long dp[1025][1025];

int main() {
	//freopen("sample_input.txt", "r", stdin);
	
	scanf("%d", &N);
	scanf("%d", &M);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &arr[i][j]);
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];
		}
	}

	for (int i = 0; i < M; i++)
	{
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &y1, &x1, &y2, &x2);

		int sum = 0;
		sum += dp[y2][x2] - dp[y2][x1 - 1] - dp[y1 - 1][x2] + dp[y1 - 1][x1 - 1];
		
		printf("%lld\n", sum);
	}
}