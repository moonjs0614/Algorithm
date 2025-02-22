#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

#define mod 1000000

int n;

void solution()
{
	long long ans = 0;

	for (int i = 2; i <= (n / 2); i++)
	{
		ans += (n / i - 1) * i;
	}

	cout << ans % mod;
}

int main() {
	cin >> n;

	solution();
}