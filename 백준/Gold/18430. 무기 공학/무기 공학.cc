#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int N, M;
int arr[6][6];
bool visited[6][6];
int answer = 0;

void input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}
}

int one(int y, int x)
{
	return (arr[y][x - 1] + arr[y][x] * 2 + arr[y + 1][x]);
}

int two(int y, int x)
{
	return (arr[y][x - 1] + arr[y][x] * 2 + arr[y - 1][x]);
}

int three(int y, int x)
{
	return (arr[y + 1][x] + arr[y][x] * 2 + arr[y][x + 1]);
}

int four(int y, int x)
{
	return (arr[y - 1][x] + arr[y][x] * 2 + arr[y][x + 1]);
}

void dfs(int y, int x, int sum)
{
	if (x == M)
	{
		y++;
		x = 0;
	}
	if (y == N)
	{
		answer = max(answer, sum);
		return;
	}

	if (!visited[y][x])
	{
		// 1번 모양
		if (y + 1 < N && x - 1 >= 0 && !visited[y][x - 1] && !visited[y + 1][x])
		{
			visited[y][x] = true;
			visited[y][x - 1] = true;
			visited[y + 1][x] = true;

			dfs(y, x + 1, sum + one(y, x));

			visited[y][x] = false;
			visited[y][x - 1] = false;
			visited[y + 1][x] = false;
		}

		// 2번 모양
		if (x - 1 >= 0 && y - 1 >= 0 && !visited[y][x - 1] && !visited[y - 1][x])
		{
			visited[y][x] = true;
			visited[y][x - 1] = true;
			visited[y - 1][x] = true;

			dfs(y, x + 1, sum + two(y, x));

			visited[y][x] = false;
			visited[y][x - 1] = false;
			visited[y - 1][x] = false;
		}

		// 3번 모양
		if (y + 1 < N && x + 1 < M && !visited[y + 1][x] && !visited[y][x + 1])
		{
			visited[y][x] = true;
			visited[y + 1][x] = true;
			visited[y][x + 1] = true;

			dfs(y, x + 1, sum + three(y, x));

			visited[y][x] = false;
			visited[y + 1][x] = false;
			visited[y][x + 1] = false;
		}

		// 4번 모양
		if (y - 1 >= 0 && x + 1 < M && !visited[y - 1][x] && !visited[y][x + 1])
		{
			visited[y][x] = true;
			visited[y - 1][x] = true;
			visited[y][x + 1] = true;

			dfs(y, x + 1, sum + four(y, x));

			visited[y][x] = false;
			visited[y - 1][x] = false;
			visited[y][x + 1] = false;
		}
	}

	dfs(y, x + 1, sum);
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	input();

	if (N == 1 || M == 1)
	{
		answer = 0;
	}
	else
	{
		dfs(0, 0, 0);
	}

	cout << answer << endl;
}