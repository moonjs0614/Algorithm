#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int N;
pair<char, char> node[26];

void input()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		char root, left, right;
		cin >> root >> left >> right;

		node[root - 'A'].first = left;
		node[root - 'A'].second = right;
	}
}

void preorder(char now)
{
	if (now == '.') return;

	cout << now;
	preorder(node[now - 'A'].first);
	preorder(node[now - 'A'].second);
}

void inorder(char now)
{
	if (now == '.') return;

	inorder(node[now - 'A'].first);
	cout << now;
	inorder(node[now - 'A'].second);
}

void postorder(char now)
{
	if (now == '.') return;

	postorder(node[now - 'A'].first);
	postorder(node[now - 'A'].second);
	cout << now;
}

void solution()
{
	preorder('A');
	cout << endl;
	inorder('A');
	cout << endl;
	postorder('A');
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	input();
	solution();
}