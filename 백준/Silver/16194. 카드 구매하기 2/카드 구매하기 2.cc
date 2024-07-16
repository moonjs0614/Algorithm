#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int packs[1001];
int dp[1001] = { 0, };

void input()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> packs[i];
	}
}

void solution()
{
	for (int i = 1; i <= N; i++)
	{
		dp[i] = packs[i];
		for (int j = 1; j <= i; j++)
		{
			dp[i] = min(dp[i], dp[i - j] + dp[j]);
		}
	}
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	input();

	solution();

	cout << dp[N] << endl;
}