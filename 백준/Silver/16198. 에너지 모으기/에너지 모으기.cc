#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> v;
int maxval = 0;

void input()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
}

void back(vector<int>& v, int ans)
{
	if (v.size() == 3)
	{
		ans += (v[0] * v[2]);
		maxval = max(maxval, ans);

		return;
	}

	for (int i = 0; i < v.size() - 2; i++)
	{
		vector<int> copy = v;
		copy.erase(copy.begin() + i + 1);

		back(copy, ans + (v[i] * v[i + 2]));
	}
}

void solution()
{
	back(v, 0);

	cout << maxval << endl;
}

int main() {
	// freopen("sample_input.txt", "r", stdin);
	input();

	solution();
}