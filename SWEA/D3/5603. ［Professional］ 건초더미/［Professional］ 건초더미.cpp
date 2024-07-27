#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int N;
int sum = 0;
int arr[10000];
int deviation[10000];
int ans = 0;

void init()
{
	memset(arr, 0, sizeof(arr));
	memset(deviation, 0, sizeof(deviation));
	sum = 0;
	ans = 0;
}

void input()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}
}

void solution()
{
	int avg = sum / N;
	for (int i = 0; i < N; i++)
	{
		deviation[i] = arr[i] - avg;
		if (deviation[i] > 0)
		{
			ans += deviation[i];
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		init();
		input();

		solution();

		cout << "#" << tc << " " << ans << endl;
	}
}