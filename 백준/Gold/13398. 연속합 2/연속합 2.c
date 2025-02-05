#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX(x, y) x > y ? x : y

int N;
int arr[100010];
long long left_sum[100010];
long long right_sum[100010];
int max_val = 0;

void input()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &arr[i]);
	}
}

void solution()
{
	if (N == 1)
	{
		printf("%d", arr[1]);
		return;
	}

	// left_sum
	left_sum[1] = arr[1];
    max_val = arr[1];
	for (int i = 2; i <= N; i++)
	{
		int a = left_sum[i - 1] + arr[i];
		int b = arr[i];

		left_sum[i] = MAX(a, b);

		max_val = MAX(left_sum[i], max_val);
	}

	// right_sum
	right_sum[N] = arr[N];
	for (int i = N - 1; i >= 1; i--)
	{
		int a = right_sum[i + 1] + arr[i];
		int b = arr[i];

		right_sum[i] = MAX(a, b);
	}

	for (int i = 1; i <= N; i++)
	{
		max_val = MAX(max_val, left_sum[i - 1] + right_sum[i + 1]);
	}

	printf("%d", max_val);
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	input();

	solution();
}