#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, K;
int minTime = 21e8;
int visited[100001] = { 0, };

void bfs()
{
	queue<int> q;
	q.push(N);

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		if (now < 0 || now > 100000) continue;
		if (now == K)
		{
			cout << visited[now];
			break;
		}

		if (now - 1 >= 0 && visited[now - 1] == 0)
		{
			visited[now - 1] = visited[now] + 1;
			q.push(now - 1);
		}
		if (now + 1 <= 100000 && visited[now + 1] == 0)
		{
			visited[now + 1] = visited[now] + 1;
			q.push(now + 1);
		}
		if (now * 2 <= 100000 && visited[now * 2] == 0)
		{
			visited[now * 2] = visited[now] + 1;
			q.push(now * 2);
		}
	}
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	cin >> N >> K;

	bfs();
}