#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int N; // 시험장의 개수
int arr[1000001]; // 각 시험장의 응시자 수
long long res;
int b; // 총감독관의 감시 가능 수
int c; // 부감독관의 감시 가능 수
// 한 시험장에 총감은 오직 1명, 부감은 여러명 가능
// 필요한 감독관의 수?

void input()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}
	cin >> b >> c;
}

void solution()
{
	for (int i = 1; i <= N; i++)
	{
		int cnt = 0;
		int num = arr[i];
		num -= b;
		cnt++; // 총감 1명 배치

		if (num > 0)
		{
			if (num <= c)
			{
				cnt++;
			}
			else
			{
				cnt += num / c;
				if (num % c > 0)
				{
					cnt++;
				}
			}
		}
		res += cnt;
	}
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	input();

	solution();

	cout << res << endl;
}