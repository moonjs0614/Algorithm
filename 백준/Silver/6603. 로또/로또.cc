#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int k;
int arr[13];
int lotto[13];
int visited[13];

void print()
{
	for (int i = 0; i < 6; i++)
	{
		cout << lotto[i] << " ";
	}
	cout << endl;
}

void dfs(int start, int level)
{
	if (level == 6)
	{
		print();
		return;
	}

	for (int i = start; i < k; i++)
	{
		lotto[level] = arr[i];
		dfs(i + 1, level + 1);
	}
}

void solution()
{
	dfs(0, 0);
}

void input()
{
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> arr[i];
	}
}

int main() {
	//freopen("sample_input.txt", "r", stdin);

	while (1)
	{
		input();

		if (k == 0) break;
		solution();
		cout << endl;
	}
}