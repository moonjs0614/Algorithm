#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int N, M;
int video[100000] = { 0, };

void input()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> video[i];
	}
}

void solution()
{
	int low = 1;
	int high = 1000000000;
	int result = 0;

	while (low <= high)
	{
		int mid = (low + high) / 2; // 블루레이 한 개의 크기

		int cnt = 1;
		int sum = 0;

		for (int i = 0; i < N; i++)
		{
			if (mid < video[i])
			{
				cnt = M + 1;
				break;
			}

			if (sum + video[i] <= mid)
			{
				sum += video[i];
			}
			else
			{
				sum = video[i];
				cnt += 1;
			}
		}

		if (cnt <= M)
		{
			result = mid;
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}


	cout << result << endl;
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	input();

	solution();
}