#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N; // 보드의 크기
int K; // 사과의 개수
int L; // 방향 변환 횟수
int t = 0; // 시간
int d = 3; // 뱀의 방향
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int rot[4][3] = { {0, 2, 3}, {1, 3, 2}, {2, 1, 0}, {3, 0, 1} }; // 방향 전환에 따른 바뀐 방향 배열
struct Point
{
	int y;
	int x;
};
struct Rotation
{
	int t;
	char d;
};
queue<Point> snake; // 뱀 큐
queue<Point> apples; // 사과 큐
queue<Rotation> dir; // 방향 전환 정보

void input()
{
	cin >> N;
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int y, x;
		cin >> y >> x;
		apples.push({ y, x });
	}
	cin >> L;
	for (int i = 0; i < L; i++)
	{
		int t;
		char d;
		cin >> t >> d;
		dir.push({ t, d });
	}
	snake.push({ 1, 1 }); // 뱀의 초기 정보 추가
}

void solution()
{
	while (true)
	{
		t++; // 시간 ++

		Point now = snake.back();
		Point next = { now.y + dy[d], now.x + dx[d] };
		int flag = 0;

		for (int i = 0; i < snake.size(); i++)
		{
			Point p = snake.front();
			snake.pop();

			if (next.y == p.y && next.x == p.x) // 만약 뱀이 자기 몸통과 부딪쳤다면
			{
				return; // 리턴하며 함수 종료
			}
			else if (next.y < 1 || next.x < 1 || next.y > N || next.x > N)
			{
				return;
			}
			else
			{
				snake.push(p); // 다시 넣어주기
			}
		}

		snake.push(next); // 이동한 칸 추가하여 뱀 길이 늘리기

		if (t == 14)
		{
			int de = -1;
		}

		for (int i = 0; i < apples.size(); i++)
		{
			Point apple = apples.front();
			apples.pop();
			if (next.y == apple.y && next.x == apple.x) // 이동한 칸에서 사과를 먹는다면
			{
				flag = 1;
				break;
			}
			apples.push(apple);
		}

		if (flag == 0) // 이동한 칸에서 사과를 못먹었으면
		{
			snake.pop(); // 꼬리칸 빼주면서 뱀 길이 유지
		}

		if (!dir.empty())
		{
			Rotation noow = dir.front();
			if (noow.t == t) // 방향을 바꿀 차례라면
			{
				dir.pop();

				if (noow.d == 'L')
				{
					d = rot[d][1];
				}
				else if (noow.d == 'D')
				{
					d = rot[d][2];
				}
			}
		}
	}
}

int main() {
	//freopen("sample.txt", "r", stdin);
	input();

	solution();

	cout << t << endl;
}