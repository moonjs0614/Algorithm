#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int N, K;
int st, en;
int answer_cnt = 0;
int answer[1001];

struct Code
{
	int num;
	string data;
};
vector<Code> codes(1111);
int graph[1111][1111] = { 0, };

void input()
{
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		Code temp;
		temp.num = i;
		cin >> temp.data;
		codes[i] = temp;
	}
	cin >> st >> en;
}

int hamming_dist(string now, string next)
{
	int dist = 0;
	for (int i = 0; i < K; i++)
	{
		if (now[i] != next[i]) dist++;
	}

	return dist;
}

void bfs()
{
	int visited[1111] = { 0, };
	int path[1111] = { 0, };
	queue<int> q;
	q.push(st);

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		for (int i = 1; i <= N; i++)
		{
			int next = i;
			if (visited[i] == 1) continue;
			if (graph[now][next] == 0 || graph[next][now] == 0) continue;

			visited[now] = 1;
			path[next] = now;

			if (next == en) break;

			q.push(next);
		}
	}

	// 도착
	if (path[en])
	{
		answer[answer_cnt++] = en;
		while (path[en])
		{
			answer[answer_cnt++] = path[en];
			en = path[en];
		}

		for (int i = answer_cnt - 1; i > -1; i--)
		{
			cout << answer[i] << " ";
		}
	}
	// 경로 없음
	else
	{
		cout << -1;
	}
}

void solution()
{
	Code start = codes[st];
	Code end = codes[en];
	int cnt = 0;

	// 2차원 그래프 제작
	for (int i = 1; i < N; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			int dist = hamming_dist(codes[i].data, codes[j].data);

			if (dist == 1) graph[i][j] = graph[j][i] = 1;
			else graph[i][j] = graph[j][i] = 0;
		}
	}

	// 그래프 탐색
	bfs();
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	input();

	solution();
}