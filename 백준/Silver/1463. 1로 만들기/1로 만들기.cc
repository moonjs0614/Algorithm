#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int n;
int dp[1000001] = { 0, };

void solution()
{
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i <= n; i++)
	{
		int a = 21e8;
		int b = 21e8;
		int c = 21e8;
		if (i % 2 == 0) a = dp[i / 2] + 1;
		if (i % 3 == 0) b = dp[i / 3] + 1;
		c = dp[i - 1] + 1;

		dp[i] = min(a, min(b, c));
	}
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	cin >> n;

	solution();

	cout << dp[n];
}