#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int N, K;

struct Point
{
	int y, x;
};

Point homes[50];

void input()
{
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;

		homes[i] = { x, y };
	}
}

int cal(Point a, Point b, Point c)
{
	int ans = 0;

	for (int i = 0; i < N; i++)
	{
		int d1 = abs(a.x - homes[i].x) + abs(a.y - homes[i].y);
		int d2 = abs(b.x - homes[i].x) + abs(b.y - homes[i].y);
		int d3 = abs(c.x - homes[i].x) + abs(c.y - homes[i].y);

		ans = max(ans, min({ d1, d2, d3 }));
	}

	return ans;
}

void solution()
{
	int ans = 987654321;

	if (K == 1)
	{
		for (int i = 0; i < N; i++)
		{
			ans = min(ans, cal(homes[i], homes[i], homes[i]));
		}
	}
	else if (K == 2)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = i; j < N; j++)
			{
				ans = min(ans, cal(homes[i], homes[j], homes[j]));
			}
		}
	}
	else if (K == 3)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = i; j < N; j++)
			{
				for (int k = j; k < N; k++)
				{
					ans = min(ans, cal(homes[i], homes[j], homes[k]));
				}
			}
		}
	}

	cout << ans;
}

int main() {
	//freopen("sample_input.txt", "r", stdin);

	input();

	solution();
}