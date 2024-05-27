#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int map[21][21];
int dy[4] = { 1, 1, -1, -1 };
int dx[4] = { 1, -1 ,-1, 1 };
int visited[101] = { 0, };
int answer = -1;
int flag = 0;
struct Point
{
    int y, x;
};

void init()
{
    memset(map, 0, sizeof(map));
    memset(visited, 0, sizeof(visited));
    answer = -1;
    flag = 0;
}

void input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
        }
    }
}

void dfs(Point now, Point st, int dir, int level)
{
    if (dir == 3 && now.y == st.y && now.x == st.x)
    {
        answer = max(answer, level);
        flag = 1;
        return;
    }

    for (int i = dir; i <= dir + 1; i++)
    {
        Point next = { 0, };
        next.y = now.y + dy[i];
        next.x = now.x + dx[i];

        if (next.y < 0 || next.x < 0 || next.y >= N || next.x >= N) continue;
        if (visited[map[next.y][next.x]] != 0) continue;

        visited[map[next.y][next.x]] = 1;

        dfs(next, st, i, level + 1);

        visited[map[next.y][next.x]] = 0;
    }
}

void solution()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == 0 && j == 0 || i == N - 1 && j == 0 || i == 0 && j == N - 1 || i == N - 1 && j == N - 1) continue;
            memset(visited, 0, sizeof(visited));
            flag = 0;
            dfs({ i, j }, { i, j }, 0, 0);
        }
    }
}

int main() {
    //freopen("sample_input.txt", "r", stdin);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        init();
        input();

        solution();

        cout << "#" << tc << " " << answer << endl;
    }
}