#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int n;
long long arr[100001][4];
long long dp[100001];

void init()
{
	memset(dp, 0, sizeof(dp));
	memset(arr, 0, sizeof(arr));
}

void input()
{
	cin >> n;
}

void solution()
{
	arr[1][1] = 1;
	arr[2][2] = 1;
	arr[3][1] = 1;
	arr[3][2] = 1;
	arr[3][3] = 1;

	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 3;
	
	for (int i = 4; i <= n; i++)
	{
		arr[i][1] = (arr[i - 1][2] + arr[i - 1][3]) % 1000000009; // 맨 뒤에 1을 더하는 경우
		arr[i][2] = (arr[i - 2][1] + arr[i - 2][3]) % 1000000009; // 맨 뒤에 2를 더하는 경우
		arr[i][3] = (arr[i - 3][1] + arr[i - 3][2]) % 1000000009; // 맨 뒤에 3을 더하는 경우

		dp[i] = (arr[i][1] + arr[i][2] + arr[i][3]) % 1000000009;
	}
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		init();
		input();

		solution();

		cout << dp[n] % 1000000009 << endl;
	}
}