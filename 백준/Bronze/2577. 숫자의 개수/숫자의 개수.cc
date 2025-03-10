#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int A, B, C;
int idx[10];

int main() {
	//freopen("sample_input.txt", "r", stdin);
	cin >> A >> B >> C;

	int res = A * B * C;
	string str = to_string(res);

	for (int i = 0; i < str.length(); i++)
	{
		int num = str[i] - '0';
		idx[num]++;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << idx[i] << endl;
	}
}