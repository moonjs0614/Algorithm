#include <iostream>
using namespace std;

int arr[1001];
int a, b;
int sum = 0;

void make_arr()
{
	int num = 1;
	int cnt = 1;

	for (int i = 1; i < 1001; i++)
	{
		arr[i] = num;

		if (cnt == num)
		{
			cnt = 1;
			num++;
			continue;
		}

		cnt++;
	}
}

int main() {

	make_arr();

	cin >> a >> b;

	for (int i = a; i <= b; i++)
	{
		sum += arr[i];
	}

	cout << sum;
}