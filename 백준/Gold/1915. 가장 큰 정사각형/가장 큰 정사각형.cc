#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int N, M;
int arr[1000][1000];
int dp[1000][1000];
int answer = 0;

void input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = int(temp[j]) - 48;
		}
	}
}

void solution()
{
	if (N == 1 || M == 1)
	{
		answer = 1;
		return;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (i == 0 || j == 0)
			{
				dp[i][j] = arr[i][j];
			}
			else if (arr[i][j] == 1)
			{
				int a = dp[i - 1][j - 1];
				int b = dp[i - 1][j];
				int c = dp[i][j - 1];

				dp[i][j] = min(min(a, b), c) + 1;
			}
			answer = max(answer, dp[i][j]);
		}
	}
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	input();

	solution();

	cout << pow(answer, 2) << endl;
}