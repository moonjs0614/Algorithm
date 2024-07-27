#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> v;

void input()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		v.push_back({ num, i });
	}
}

void sorting()
{
	sort(v.begin(), v.end());

	int ans = 0;
	for (int i = 0; i < v.size(); i++)
	{
		ans = max(ans, v[i].second - i);
	}

	cout << ans + 1 << endl;
}

int main()
{
	//freopen("sample_input.txt", "r", stdin);
	input();

	sorting();
}