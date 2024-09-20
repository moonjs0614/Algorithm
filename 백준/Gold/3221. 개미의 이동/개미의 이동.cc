#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L, T;
int N;

struct Ant
{
	int loc;
	char dir;
};

Ant ants[70001];
vector<int> v;

void input()
{
	cin >> L >> T;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		Ant a;
		cin >> a.loc >> a.dir;

		ants[i] = a;
	}
}

void solution()
{
	for (int i = 1; i <= N; i++)
	{
		Ant now = ants[i];

		if (now.dir == 'L')
		{
			int new_loc = T + L - now.loc;

			if (new_loc < L)
			{
				v.push_back(L - new_loc);
			}
			else if (new_loc >= L)
			{
				if ((new_loc / L) % 2 == 1)
				{
					v.push_back(new_loc % L);
				}
				else if ((new_loc / L) % 2 == 0)
				{
					v.push_back(L - new_loc % L);
				}
			}
		}
		else if (now.dir == 'D')
		{
			int new_loc = T + now.loc;

			if (new_loc < L)
			{
				v.push_back(new_loc);
			}
			else
			{
				if ((new_loc / L) % 2 == 1)
				{
					v.push_back(L - new_loc % L);
				}
				else
				{
					v.push_back(new_loc % L);
				}
			}
		}
	}

	sort(v.begin(), v.end());
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	input();

	solution();

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
}