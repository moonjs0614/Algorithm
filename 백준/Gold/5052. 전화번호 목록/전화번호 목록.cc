#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N;
vector<string> v;

void init()
{
	v.clear();
}

void input()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string a;
		cin >> a;
		v.push_back(a);
	}
}

void solution()
{
	sort(v.begin(), v.end());

	bool flag = true;

	for (int i = 0; i < N - 1; i++)
	{
		string now = v[i];
		string next = v[i + 1];

		if (now.length() > next.length()) continue;
		if (now == next.substr(0, now.length()))
		{
			flag = false;
			break;
		}
	}

	if (flag) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		init();
		input();

		solution();
	}
}