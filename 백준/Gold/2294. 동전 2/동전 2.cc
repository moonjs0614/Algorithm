#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 21e8
using namespace std;

int main() {
	//freopen("sample_input.txt", "r", stdin);
	int n, k;
	cin >> n >> k;
	vector<int> coins(n + 1);
	vector<int> dp(k + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> coins[i];
	}

	for (int i = 1; i <= k; i++)
	{
		dp[i] = INF;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = coins[i]; j <= k; j++)
		{
			dp[j] = min(dp[j], dp[j - coins[i]] + 1);
		}
	}

	if (dp[k] == INF) cout << -1;
	else cout << dp[k];
}