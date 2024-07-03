#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int n;
long long dp[91] = { 0, };

void solution()
{
	dp[1] = 1;
	dp[2] = 1;

	for (int i = 3; i <= n; i++)
	{
		dp[i] = dp[i - 2] + dp[i - 1];
	}
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	cin >> n;

	solution();

	cout << dp[n];
}