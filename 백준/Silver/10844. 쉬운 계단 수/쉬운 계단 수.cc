#include <iostream>
#define billion 1000000000
using namespace std;

int N; // 1 <= N <= 100
int dp[101][10];
int ans = 0;

void solution()
{
	for (int i = 1; i <= 9; i++)
	{
		dp[1][i] = 1;
	}

	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (j == 0)
			{
				dp[i][j] = dp[i - 1][j + 1] % billion;
			}
			else if (j == 9)
			{
				dp[i][j] = dp[i - 1][j - 1] % billion;
			}
			else
			{
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % billion;
			}
		}
	}
}

int main() {
	cin >> N;

	solution();

	for (int i = 0; i <= 9; i++)
	{
		ans = (ans + dp[N][i]) % billion;
	}

	cout << ans << endl;
}