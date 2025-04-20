#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int N;
int cnt = 0;

int main() {
	//freopen("sample_input.txt", "r", stdin);
	cin >> N;

	for (int i = 1; i <= N; i *= 10)
	{
		cnt += N - i + 1;
	}

	cout << cnt;
}