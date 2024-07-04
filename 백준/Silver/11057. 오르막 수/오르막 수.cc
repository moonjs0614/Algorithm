#include <iostream>
#include <cmath>
using namespace std;

int N;
int answer = 0;
int dp[1001][11] = {0,};

void solution()
{
	for (int i = 0; i < 10; i++)
	{
		dp[1][i] = 1;
	}

	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			dp[i][j] = 0;
			for (int k = 0; k <= j; k++)
			{
				dp[i][j] += dp[i - 1][k];
				dp[i][j] %= 10007;
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		answer += dp[N][i];
	}
}

int main() {
	cin >> N;

	solution();

	cout << answer % 10007 << endl;
}