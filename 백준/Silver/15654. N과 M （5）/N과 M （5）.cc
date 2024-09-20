#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<int> v;
vector<int> answer;
int visited[10001];

void input()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}
}

void print()
{
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << " ";
	}
	cout << "\n";
}

void back(int level)
{
	if (level == M)
	{
		print();
		return;
	}

	for (int i = 0; i < v.size(); i++)
	{
		int num = v[i];

		if (visited[num] == 1) continue;

		answer.push_back(num);
		visited[num] = 1;

		back(level + 1);

		answer.pop_back();
		visited[num] = 0;
	}
}

void solution()
{
	sort(v.begin(), v.end());

	back(0);
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	cin.tie(NULL);

	input();

	solution();
}