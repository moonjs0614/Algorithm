#include <iostream>
using namespace std;

int N;
int arr[100];
int cnt = 0;

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
		bool flag = false;
		int num = arr[i];

		if (num == 1) continue;

		for (int j = 2; j < num; j++)
		{
			if (num % j == 0)
			{
				flag = true;
				break;
			}
		}

		if (flag == false) cnt++;
	}
}

int main() {
	input();

	solution();

	cout << cnt << endl;
}