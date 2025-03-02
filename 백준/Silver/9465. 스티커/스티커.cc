#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[2][100000];
int dp[2][100000];

void init()
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 10000; j++)
		{
			arr[i][j] = 0;
			dp[i][j] = 0;
		}
	}
}

void input()
{
	cin >> n;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
}

void solution()
{
	dp[0][0] = arr[0][0];
	dp[1][0] = arr[1][0];
	dp[0][1] = arr[0][1] + dp[1][0];
	dp[1][1] = arr[1][1] + dp[0][0];

	for (int col = 2; col < n; col++)
	{
		for (int row = 0; row < 2; row++)
		{
			if (row == 0)
			{
				dp[row][col] = arr[row][col] + max(dp[1][col - 1], dp[1][col - 2]);
			}
			else if (row == 1)
			{
				dp[row][col] = arr[row][col] + max(dp[0][col - 1], dp[0][col - 2]);
			}
		}
	}

	cout << max(dp[0][n - 1], dp[1][n - 1]) << endl;
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		if (tc == 2)
		{
			int de = -1;
		}
		init();
		input();
		solution();
	}
}