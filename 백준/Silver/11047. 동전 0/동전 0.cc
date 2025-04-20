#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int N, K;
int coins[10];

void input()
{
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> coins[i];
	}
}

void solution()
{
	int cnt = 0;

	for (int i = N - 1; i >= 0; i--)
	{
		if (coins[i] <= K)
		{
			cnt += K / coins[i];
			K %= coins[i];
		}
	}
	cout << cnt;
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	input();

	solution();
}