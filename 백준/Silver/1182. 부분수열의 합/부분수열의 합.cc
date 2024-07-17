#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int N, S;
int nums[20];
int visited[20] = { 0, };
int cnt = 0;

void input()
{
	cin >> N >> S;
	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
	}
}

void back(int now, int sum)
{
	if (now == N) return;
	if (sum + nums[now] == S) cnt++;

	back(now + 1, sum);
	back(now + 1, sum + nums[now]);
}

void solution()
{
	back(0, 0);
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	input();

	solution();

	cout << cnt;
}