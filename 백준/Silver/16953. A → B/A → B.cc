#include <iostream>
using namespace std;

int a, b;
int cnt = 0;
bool flag = false;

int half(int num)
{
	return num / 2;
}

int moduler_ten(int num)
{
	return num / 10;
}

void solution()
{
	// b를 a로 바꾸기
	while (b > a)
	{
		bool able = false;
		if (b % 2 == 0)
		{
			b = half(b);
			cnt++;
			able = true;
		}
		else if (b % 10 == 1)
		{
			b = moduler_ten(b);
			cnt++;
			able = true;
		}

		if (a == b)
		{
			flag = true;
		}

		if (able == false) break;
	}

	if (flag)
	{
		cout << cnt + 1;
	}
	else
	{
		cout << -1;
	}
}

int main() {
	cin >> a >> b;

	solution();
}