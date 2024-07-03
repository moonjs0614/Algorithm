#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
using namespace std;

int n;
int dp[100001] = { 0, };

void solution()
{
	for (int i = 1; i <= n; i++)
	{
		dp[i] = i;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j * j <= i; j++)
		{
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	cin >> n;

	solution();

	cout << dp[n];
}