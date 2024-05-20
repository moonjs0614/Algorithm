#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N; //수의 개수
vector<int> nums; // 수 벡터
vector<char> path; // 연산자 조합 벡터
int ops[4]; // 연산자 배열
int max_res = -1e10;
int min_res = 1e10;

void input()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int num;
		cin >> num;
		nums.push_back(num);
	}
	for (int i = 0; i < 4; i++)
	{
		cin >> ops[i];
	}
}

void cal()
{
	int res = nums[0];

	for (int i = 0; i < path.size(); i++)
	{
		int num = nums[i + 1];
		char op = path[i];

		if (op == '+') res += num;
		else if (op == '-') res -= num;
		else if (op == '*') res *= num;
		else if (op == '/') res /= num;
	}

	max_res = max(max_res, res);
	min_res = min(min_res, res);
}

void dfs(int now)
{
	if (now >= N - 1)
	{
		cal();
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (ops[i] == 0) continue;

		char op = '0';

		if (i == 0) op = '+';
		else if (i == 1) op = '-';
		else if (i == 2) op = '*';
		else if (i == 3) op = '/';

		path.push_back(op);
		ops[i]--;

		dfs(now + 1);

		path.pop_back();
		ops[i]++;
	}
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	input();

	dfs(0);

	cout << max_res << endl;
	cout << min_res << endl;
}