#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int n;
long long arr[1000001][4];
long long dp[1000001];

void solution()
{
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i <= 1000000; i++)
	{
		dp[i] = (dp[i - 3] + dp[i - 2] + dp[i - 1]) % 1000000009;
	}
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	
	solution();

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		cin >> n;
		cout << dp[n] % 1000000009 << endl;
	}
}