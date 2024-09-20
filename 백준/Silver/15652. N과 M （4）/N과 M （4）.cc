#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> v;

void input()
{
	cin >> N >> M;
}

void print()
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

void back(int level, int now)
{
	if (level == M)
	{
		print();
		return;
	}

	for (int i = now; i <= N; i++)
	{
		//if (v.size() > 0 && i < v[i - 1]) continue;
		v.push_back(i);
		back(level + 1, i);
		v.pop_back();
	}
}

void solution()
{
	back(0, 1);
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	input();

	solution();
}