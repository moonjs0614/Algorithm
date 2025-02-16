#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M;
int map[50][50];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int stCnt = 0;
bool virus_visited[10];
int result = 2500;

struct Point
{
	int y, x;
};
vector<Point> v; // 비활성 바이러스 벡터
vector<Point> selected;

void input()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == 2)
			{
				v.push_back({ i, j });
			}

			if (map[i][j] == 0)
			{
				stCnt++;
			}
		}
	}
}

void bfs()
{
	queue<Point> q;
	int visited[50][50];
	memset(visited, -1, sizeof(visited));
	int time = 0;
	int cnt = 0;
	
	for (int i = 0; i < M; i++)
	{
		q.push(selected[i]);
		visited[selected[i].y][selected[i].x] = 0;
	}

	while (!q.empty())
	{
		Point now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			Point next = { now.y + dy[i], now.x + dx[i] };

			if (next.y < 0 || next.x < 0 || next.y >= N || next.x >= N) continue;
			if (map[next.y][next.x] == 1) continue;
			if (visited[next.y][next.x] != -1) continue;

			q.push(next);
			visited[next.y][next.x] = visited[now.y][now.x] + 1;

			if (map[next.y][next.x] == 0)
			{
				cnt++;
				time = visited[next.y][next.x];
			}
		}
	}
	
	if (cnt == stCnt)
	{
		result = min(result, time);
	}

	int de = -1;
}

void selectVirus(int idx, int cnt)
{
	if (cnt == M)
	{
		// bfs 실행
		bfs();
	
		return;
	}

	for (int i = idx; i < v.size(); i++)
	{
		if (virus_visited[i]) continue;

		selected.push_back({ v[i].y, v[i].x });
		virus_visited[i] = true;

		selectVirus(i + 1, cnt + 1);

		selected.pop_back();
		virus_visited[i] = false;
	}
}

void solution()
{
	// M개의 비활성 바이러스 선택
	selectVirus(0, 0);

	if (result != 2500)
	{
		cout << result;
	}
	else
	{
		cout << -1;
	}
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	input();
	solution();
}