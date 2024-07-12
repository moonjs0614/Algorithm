#include <iostream>
using namespace std;

int N;
long long dp[31] = { 0, };


int main() {
	cin >> N;

	if (N % 2 == 1)
	{
		cout << 0;
		return 0;
	}
	else
	{
		dp[0] = 1;
		dp[1] = 0;
		dp[2] = 3;

		for (int i = 4; i <= N; i+=2)
		{
			dp[i] = dp[i - 2] * dp[2];
			for (int j = i - 4; j >= 0; j -= 2)
			{
				dp[i] += dp[j] * 2;
			}
		}

		cout << dp[N];
	}
}