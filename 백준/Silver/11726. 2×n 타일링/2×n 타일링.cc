#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int n;
long long dp[1001];

void solution()
{
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++)
	{
		dp[i] = (dp[i - 2] + dp[i - 1]) % 10007;
	}

	cout << dp[n];
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	cin >> n;

	solution();
}