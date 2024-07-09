#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[1001] = { 0, };
int dp[1001] = { 0, };

void input()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}
}

void solution()
{
	for (int i = 1; i <= N; i++)
	{
		dp[i] = 1;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	sort(dp, dp + N + 1);
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	input();

	solution();

	cout << dp[N] << endl;
}