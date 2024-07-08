#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[1001][1001];

// dp[i][0] => i번째 집을 빨간색으로 칠했을 때의 최소값
// dp[i][1] => i번째 집을 초록색으로 칠했을 때의 최소값
// dp[i][2] => i번째 집을 파란색으로 칠했을 때의 최소값
long long dp[1001][3] = {0,};

void input()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> arr[i][j];
		}
	}
}

void solution()
{
	dp[1][0] = arr[1][0];
	dp[1][1] = arr[1][1];
	dp[1][2] = arr[1][2];

	for (int i = 2; i <= N; i++)
	{
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
	}
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	input();

	solution();

	cout << min(dp[N][0], min(dp[N][1], dp[N][2]));
}