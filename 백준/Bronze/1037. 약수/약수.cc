#include <iostream>
#include <algorithm>
using namespace std;

int N;
int maxval = 0;
int minval = 21e8;

void input()
{
	cin >> N;
	int num;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		maxval = max(maxval, num);
		minval = min(minval, num);
	}
}

int main() {
	input();

	cout << minval * maxval << endl;
}