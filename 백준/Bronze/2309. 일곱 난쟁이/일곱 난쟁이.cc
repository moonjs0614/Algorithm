#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
vector<int> temp;
vector<int> ans;
int sum_val;
int visited[9] = { 0, };

void input()
{
	for (int i = 0; i < 9; i++)
	{
		int num;
		cin >> num;

		v.push_back(num);
	}
}

int cal()
{
	int sum = 0;
	for (int i = 0; i < 7; i++)
	{
		sum += temp[i];
	}

	return sum;
}

void dfs(int cnt)
{
	if (cnt == 7)
	{
		sum_val = cal();
		
		if (sum_val == 100)
		{
			for (int i = 0; i < 7; i++)
			{
				ans.push_back(temp[i]);
			}
		}
		return;
	}

	for (int i = 0; i < 9; i++)
	{
		if (visited[i] == 1) continue;

		visited[i] = 1;
		temp.push_back(v[i]);

		dfs(cnt + 1);

		if (ans.size()) return;
		temp.pop_back();
		visited[i] = 0;
	}
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	input();

	dfs(0);

	sort(ans.begin(), ans.end());

	for (int i = 0; i < 7; i++)
	{
		cout << ans[i] << endl;
	}
}