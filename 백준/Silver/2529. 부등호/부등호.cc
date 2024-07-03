#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

int k;
long long max_num = 0;
long long min_num = 9999999999;
int visited[10] = { 0, };
vector<char> v;
vector<int> nums;
vector<int> max_nums;
vector<int> min_nums;

void input()
{
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		char temp;
		cin >> temp;
		v.push_back(temp);
	}
}

long long change()
{
	long long num = 0;
	for (int i = 0; i < k + 1; i++)
	{
		num += nums[i] * pow(10, k - i);
	}

	return num;
}

void dfs(int cnt)
{
	if (cnt == k + 1)
	{
		long long num = change();
		if (min_num > num)
		{
			min_num = num;
			min_nums.resize(nums.size());
			copy(nums.begin(), nums.end(), min_nums.begin());
		}
		if (max_num < num)
		{
			max_num = num;
			max_nums.resize(nums.size());
			copy(nums.begin(), nums.end(), max_nums.begin());
		}

		return;
	}

	for (int i = 0; i < 10; i++)
	{
		if (visited[i] == 1) continue;
		if (cnt > 0)
		{
			if (v[cnt - 1] == '<')
			{
				if (nums[cnt - 1] > i) continue;
			}
			else if (v[cnt - 1] == '>')
			{
				if (nums[cnt - 1] < i) continue;
			}
		}

		nums.push_back(i);
		visited[i] = 1;

		dfs(cnt + 1);

		nums.pop_back();
		visited[i] = 0;
	}
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	input();

	dfs(0);

	for (int i = 0; i < k + 1; i++)
	{
		cout << max_nums[i];
	}
	cout << endl;

	for (int i = 0; i < k + 1; i++)
	{
		cout << min_nums[i];
	}
	cout << endl;
}