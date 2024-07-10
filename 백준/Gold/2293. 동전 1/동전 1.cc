#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	//freopen("sample_input.txt", "r", stdin);
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	vector<int> dp(k + 1);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	dp[0] = 1;

	for (int i = 0; i < n; i++)
	{
		for (int j = v[i]; j <= k; j++)
		{
			dp[j] += dp[j - v[i]];
		}
	}

	cout << dp[k];
}