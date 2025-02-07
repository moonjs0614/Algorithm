#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX(x, y) x > y ? x : y
#define MIN(x, y) x < y ? x : y

int N, K;
int arr[101][2];
int bag[100001][101];
long long ans = 0;

void input()
{
	scanf("%d", &N);
	scanf("%d", &K);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d %d", &arr[i][0], &arr[i][1]);
	}
}

void solution()
{
	for (int i = 1; i <= K; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (arr[j][0] <= i)
			{
				bag[i][j] = MAX(bag[i][j - 1], bag[i - arr[j][0]][j - 1] + arr[j][1]);
			}
			else
			{
				bag[i][j] = bag[i][j - 1];
			}

			ans = MAX(ans, bag[i][j]);
		}
	}

	printf("%d", ans);
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	input();

	solution();
}