#include <iostream>
using namespace std;

int a, b;

int main() {
	cin >> a >> b;

	int b1, b2, b3;
	b1 = b / 100;
	b2 = (b % 100) / 10;
	b3 = (b % 100) % 10;

	int m1, m2, m3;
	m3 = a * b3;
	m2 = a * b2 * 10;
	m1 = a * b1 * 100;

	int ans = m1 + m2 + m3;
	
	cout << m3 << endl;
	cout << m2 / 10 << endl;
	cout << m1 / 100 << endl;
	cout << ans;
}