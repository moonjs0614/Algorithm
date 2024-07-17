#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int N;
string arr[10];
int alphabet[91] = { 0, };
int cnt = 0;
int answer = 0;

void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
}

void solution()
{
	for (int i = 0; i < N; i++)
	{
		string s = arr[i];

		for (int j = 0; j < arr[i].length(); j++)
		{
			char c = arr[i][j];
			int power = arr[i].length() - (j + 1);

			if (alphabet[int(c)] == 0) cnt++;
			alphabet[int(c)] += pow(10, power);
		}
	}

	int num = 9;

	for (int i = 0; i < cnt; i++)
	{
		int maxval = 0;
		int maxIdx;

		for (int j = 65; j < 91; j++)
		{
			if (maxval < alphabet[j])
			{
				maxval = alphabet[j];
				maxIdx = j;
			}
		}

		alphabet[maxIdx] = 0;
		answer += maxval * num;
		num--;
	}
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	input();

	solution();

	cout << answer;
}