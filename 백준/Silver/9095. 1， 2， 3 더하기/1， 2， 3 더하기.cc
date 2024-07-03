#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int n;
int dp[11];

void dfs(int idx, int num)
{
	if (num == 0)
	{
		dp[idx]++;
		return;
	}

	for (int i = 1; i <= 3; i++)
	{
		if (num - i < 0) continue;

		dfs(idx, num - i);
	}
}

void solution()
{
	dp[1] = 1;

	for (int i = 2; i <= 10; i++)
	{
		dfs(i, i);
	}
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	int T;
	cin >> T;

	solution();
	
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> n;
		cout << dp[n] << endl;
	}
}