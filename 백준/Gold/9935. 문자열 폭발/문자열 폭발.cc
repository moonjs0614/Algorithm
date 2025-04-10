#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

string a, b;

void solution()
{
	string temp;

	int len_a = a.length();
	int len_b = b.length();

	for (int i = 0; i < len_a; i++)
	{
		temp += a[i];

		if (temp.length() >= len_b)
		{
			bool flag = true;

			for (int j = 0; j < len_b; j++)
			{
				if (temp[temp.length() - len_b + j] != b[j])
				{
					flag = false;
					break;
				}
			}

			if (flag)
			{
				temp.erase(temp.end() - len_b, temp.end());
			}
		}
	}
	if (temp.empty())
	{
		cout << "FRULA";
	}
	else
	{
		cout << temp;
	}
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	cin >> a >> b;

	solution();
}