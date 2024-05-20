#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int arr[21][21];
vector<int> v;
vector<int> ind;
vector<int> a;
vector<int> b;
int min_gap = 21e8;

void input()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];
		}
	}
}

int cal_a()
{
	int sum = 0;
	for (int i = 0; i < a.size() - 1; i++)
	{
		for (int j = i + 1; j < a.size(); j++)
		{
			sum += arr[a[i]][a[j]];
			sum += arr[a[j]][a[i]];
		}
	}
	return sum;
}

int cal_b()
{
	int sum = 0;
	for (int i = 0; i < b.size() - 1; i++)
	{
		for (int j = i + 1; j < b.size(); j++)
		{
			sum += arr[b[i]][b[j]];
			sum += arr[b[j]][b[i]];
		}
	}
	return sum;
}

void make_team()
{
	for (int i = 0; i < N; i++)
	{
		v.push_back(i);
	}

	for (int i = 0; i < N / 2; i++)
	{
		ind.push_back(1);
	}

	for (int i = 0; i < v.size() - (N / 2); i++)
	{
		ind.push_back(0);
	}

	sort(ind.begin(), ind.end());

	do {
		a.clear();
		b.clear();
		for (int i = 0; i < ind.size(); i++)
		{
			if (ind[i] == 1)
			{
				a.push_back(i + 1);
			}
			else if (ind[i] == 0)
			{
				b.push_back(i + 1);
			}
		}
		int team_start = cal_a();
		int team_link = cal_b();
		min_gap = min(min_gap, abs(team_start - team_link));
	} while (next_permutation(ind.begin(), ind.end()));
}



int main() {
	//freopen("sample.txt", "r", stdin);
	input();

	make_team();

	cout << min_gap << endl;
}