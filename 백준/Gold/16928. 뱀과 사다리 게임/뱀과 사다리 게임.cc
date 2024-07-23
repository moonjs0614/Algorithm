#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

int N, M;
int t1, t2;
int map[102] = { 0, };
bool visited[102] = { 0, };

void input()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> t1 >> t2;
		map[t1] = t2;
	}

	for (int i = 0; i < M; i++)
	{
		cin >> t1 >> t2;
		map[t1] = t2;
	}
}

void bfs(int x, int cnt)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, cnt));

	while (!q.empty())
	{
		int now = q.front().first;
		int cnt = q.front().second;
		q.pop();

		for (int i = 1; i <= 6; i++)
		{
			int next = now + i;

			if (next == 100)
			{
				cout << cnt + 1;
				return;
			}
			else if (next < 100)
			{
				while (map[next] != 0)
				{
					next = map[next];
				}

				if (!visited[next])
				{
					q.push(make_pair(next, cnt + 1));
					visited[next] = true;
				}
			}
		}
	}
}

void solution()
{
	bfs(1, 0);
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	input();

	solution();
}