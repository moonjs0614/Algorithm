#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int idx;
int dp[100001] = { 0, };
int nums[100001] = { 0, };

void input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
		dp[i] = nums[i];
	}
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	input();

	int maxsum = dp[0];
	for (int i = 1; i < n; i++)
	{
		dp[i] = max(dp[i], dp[i - 1] + nums[i]);
		maxsum = max(maxsum, dp[i]);
	}

	cout << maxsum;
}