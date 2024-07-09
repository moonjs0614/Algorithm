#include <iostream>
using namespace std;

int N;
int dp[100001];

int main() {
	cin >> N;

	dp[0] = 1;
	dp[1] = 3;

	for (int i = 2; i <= N; i++)
	{
		dp[i] += (dp[i - 2] + dp[i - 1] * 2) % 9901;
	}

	cout << dp[N] % 9901;
}