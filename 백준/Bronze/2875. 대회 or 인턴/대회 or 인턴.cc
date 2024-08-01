#include <iostream>
#include <algorithm>
using namespace std;

int N, M, K;
int maxcnt = 0;

void input()
{
	cin >> N >> M >> K;
}

void solution()
{
	for (int i = 0; i <= K; i++)
	{
		int female = N;
		int male = M;

		female -= i;
		male -= (K - i);

		int female_cnt = female / 2;
		int male_cnt = male / 1;

		int cnt = min(female_cnt, male_cnt);
		maxcnt = max(maxcnt, cnt);
	}
}

int main() {
	input();

	solution();

	cout << maxcnt << endl;
}