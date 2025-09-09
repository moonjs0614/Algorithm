#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <queue>
using namespace std;

int N;

struct serial			// 시리얼 넘버 구조체
{
	string code;
	int len;
	int sum;
};

struct cmp				// PQ 우선순위 비교 구조체
{
	bool operator() (serial a, serial b)
	{
		if (a.len == b.len)
		{
			if (a.sum == b.sum)
			{
				for (int idx = 0; idx < a.len; idx++)
				{
					if (a.code[idx] != b.code[idx])
					{
						return a.code[idx] > b.code[idx];
					}
				}
			}
			return a.sum > b.sum;
		}
		return a.len > b.len;
	}
};

priority_queue<serial, vector<serial>, cmp> pq;

void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		serial S;
		string str;
		cin >> str;
		int sum = 0;

		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] >= 48 && str[i] <= 57)
			{
				sum += (str[i] - '0');
			}
		}
		S.code = str;
		S.len = str.length();
		S.sum = sum;

		pq.push(S);
	}
}

void solution()
{
	while (!pq.empty())
	{
		serial now = pq.top();
		pq.pop();

		cout << now.code << endl;
	}
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	input();

	solution();
}