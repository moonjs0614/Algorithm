#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

int N, M;
int map[50][50];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int clean_cnt = 0;
struct Point
{
	int y, x;
	int dir;
};
Point st;
int move_back[4] = { 2, 3, 0, 1 };
int turn_left[4] = { 3, 0, 1, 2 };

void input()
{
	cin >> N >> M;
	int y, x, dir;
	cin >> y >> x >> dir;
	st = { y, x, dir };

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}
}

void bfs(Point st)
{
	queue<Point> q;
	q.push(st);

	while (!q.empty())
	{
		Point now = q.front();
		q.pop();

		if (clean_cnt == 4)
		{
			int de = -1;
		}

		if (map[now.y][now.x] == 0) // 현재 칸이 청소되어있지 않으면
		{
			map[now.y][now.x] = 2; // 청소하고
			clean_cnt++;
			q.push(now); // 다시 큐에 넣어줌
		}
		else if (map[now.y][now.x] == 2) // 현재 칸이 청소되어있으면
		{
			int cnt = 0; // 청소되지 않은 칸 카운트
			for (int i = 0; i < 4; i++) // 주변 4칸 청소 여부 확인
			{
				int ny = now.y + dy[i];
				int nx = now.x + dx[i];

				if (map[ny][nx] == 0) // 청소 X 면 cnt++
				{
					cnt++;
					break;
				}
			}

			if (cnt == 0) // 주변 4칸 중 청소되지 않은 칸이 없으면 (2번 조건)
			{
				Point next = { 0, };
				next.dir = move_back[now.dir];
				next.y = now.y + dy[next.dir];
				next.x = now.x + dx[next.dir];
				next.dir = now.dir;

				if (map[next.y][next.x] == 1) // 후진할 수 없으면 종료
				{
					return;
				}

				q.push(next);
			}
			else // 청소되지 않은 칸이 있으면 (3번 조건)
			{
				Point next = { 0, };
				next.dir = turn_left[now.dir];
				next.y = now.y + dy[next.dir];
				next.x = now.x + dx[next.dir];

				if (map[next.y][next.x] == 0)
				{
					q.push(next);
				}
				else
				{
					q.push({ now.y, now.x, next.dir });
				}
			}
		}
	}
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	input();

	bfs(st);

	cout << clean_cnt << endl;
}