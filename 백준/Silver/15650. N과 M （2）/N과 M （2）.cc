#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define MAX 9
using namespace std;

int N, M;
int arr[MAX] = { 0, };
bool visited[MAX] = { 0, };

void back(int cnt)
{
	if (cnt == M + 1)
	{
		for (int i = 1; i <= M; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	for (int i = 1; i <= N; i++)
	{
		if (visited[i] == true) continue;
		if (i < arr[cnt - 1]) continue;

		visited[i] = true;
		arr[cnt] = i;
		back(cnt + 1);
		visited[i] = false;
	}
}

void solution()
{
	back(1);
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	cin >> N >> M;

	solution();
}