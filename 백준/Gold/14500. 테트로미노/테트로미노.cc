#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int map[1000][1000];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int max_val = 0;

//---------------------- 테트로미노 하드코딩
// 상하좌우 기준으로 방향값만 넣음

int b0[3] = { 3, 1, 2 };
int b1[3] = { 3, 3, 3 };
int b2[3] = { 1, 1, 1 };
int b3[3] = { 1, 1, 3 };
int b4[3] = { 3, 1, 1 };
int b5[3] = { 1, 3, 3 };
int b6[3] = { 3, 3, 1 };
int b7[3] = { 1, 3, 1 };
int b8[3] = { 3, 1, 3 };

int b9[3] = { 3, 0, 3 }; // i == 1 부터 가능
int b10[3] = { 0, 3, 3 }; // i == 1 부터 가능
int b11[3] = { 3, 3, 0 }; // i == 1 부터 가능

int b12[3] = { 3, 0, 0 }; // i == 2 부터 가능
int b13[3] = { 0, 0, 3 }; // i == 2 부터 가능
int b14[3] = { 0, 3, 0 }; // i == 2 부터 가능

int b15[4] = { 3, 0, 1, 3 }; // i == 1 부터 가능
int b16[4] = { 1, 3, 2, 1 };
int b17[4] = { 3, 1, 0, 3 };
int b18[4] = { 1, 2, 3, 1 }; // j == 1 부터 가능

//----------------------

void input()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }
}

void solution()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            // 현재 좌표 (블록의 시작점)
            int y = i;
            int x = j;

            // 시작점의 값
            int start = map[i][j];

            // 현재 좌표에서 시작하여 넣을 수 있는 블록들 중 가장 큰 합을 가진 블록
            int max_sum = 0;
            if (i == 2 && j == 1)
            {
                int de = -1;
            }

            if (i >= 1) // 9, 10, 11번 블록 계산
            {
                for (int u = 0; u < 4; u++)
                {
                    if (u == 0)
                    {
                        int sum = start;
                        int ny = y;
                        int nx = x;
                        for (int k = 0; k < 3; k++)
                        {
                            ny = ny + dy[b9[k]];
                            nx = nx + dx[b9[k]];
                            if (ny >= N || nx >= M) break;
                            sum += map[ny][nx];
                        }
                        max_sum = max(max_sum, sum);
                    }
                    else if (u == 1)
                    {
                        int sum = start;
                        int ny = y;
                        int nx = x;
                        for (int k = 0; k < 3; k++)
                        {
                            ny = ny + dy[b10[k]];
                            nx = nx + dx[b10[k]];
                            if (ny >= N || nx >= M) break;
                            sum += map[ny][nx];
                        }
                        max_sum = max(max_sum, sum);
                    }
                    else if (u == 2)
                    {
                        int sum = start;
                        int ny = y;
                        int nx = x;
                        for (int k = 0; k < 3; k++)
                        {
                            ny = ny + dy[b11[k]];
                            nx = nx + dx[b11[k]];
                            if (ny >= N || nx >= M) break;
                            sum += map[ny][nx];
                        }
                        max_sum = max(max_sum, sum);
                    }
                    else // 15번 블록 계산
                    {
                        int sum = start;
                        int ny = y;
                        int nx = x;
                        for (int k = 0; k < 4; k++)
                        {
                            ny = ny + dy[b15[k]];
                            nx = nx + dx[b15[k]];
                            if (ny >= N || nx >= M) break;
                            if (k == 0) continue;
                            sum += map[ny][nx];
                        }
                        max_sum = max(max_sum, sum);
                    }
                }

                if (i >= 2) // 12, 13, 14번 블록 계산
                {
                    for (int s = 0; s < 3; s++)
                    {
                        if (s == 0)
                        {
                            int sum = start;
                            int ny = y;
                            int nx = x;
                            for (int k = 0; k < 3; k++)
                            {
                                ny = ny + dy[b12[k]];
                                nx = nx + dx[b12[k]];
                                if (ny >= N || nx >= M) break;
                                sum += map[ny][nx];
                            }
                            max_sum = max(max_sum, sum);
                        }
                        else if (s == 1)
                        {
                            int sum = start;
                            int ny = y;
                            int nx = x;
                            for (int k = 0; k < 3; k++)
                            {
                                ny = ny + dy[b13[k]];
                                nx = nx + dx[b13[k]];
                                if (ny >= N || nx >= M) break;
                                sum += map[ny][nx];
                            }
                            max_sum = max(max_sum, sum);
                        }
                        else
                        {
                            int sum = start;
                            int ny = y;
                            int nx = x;
                            for (int k = 0; k < 3; k++)
                            {
                                ny = ny + dy[b14[k]];
                                nx = nx + dx[b14[k]];
                                if (ny >= N || nx >= M) break;
                                sum += map[ny][nx];
                            }
                            max_sum = max(max_sum, sum);
                        }
                    }
                }
            }
            if (j >= 1) // 18번 블록 계산
            {
                int sum = start;
                int ny = y;
                int nx = x;
                for (int k = 0; k < 4; k++)
                {
                    ny = ny + dy[b18[k]];
                    nx = nx + dx[b18[k]];
                    if (ny >= N || nx >= M) break;
                    if (k == 0) continue;
                    sum += map[ny][nx];
                }
                max_sum = max(max_sum, sum);
            }

            // 항상 가능한 블록들 계산
            // 16, 17번 블록 계산
            if (1)
            {
                int sum = start;
                int ny = y;
                int nx = x;
                for (int k = 0; k < 4; k++)
                {
                    ny = ny + dy[b16[k]];
                    nx = nx + dx[b16[k]];
                    if (ny >= N || nx >= M) break;
                    if (k == 0) continue;
                    sum += map[ny][nx];
                }
                max_sum = max(max_sum, sum);
            }
            if (1)
            {
                int sum = start;
                int ny = y;
                int nx = x;
                for (int k = 0; k < 4; k++)
                {
                    ny = ny + dy[b17[k]];
                    nx = nx + dx[b17[k]];
                    if (ny >= N || nx >= M) break;
                    if (k == 0) continue;
                    sum += map[ny][nx];
                }
                max_sum = max(max_sum, sum);
            }

            // 나머지 블록 계산
            for (int g = 0; g < 9; g++)
            {
                if (g == 0)
                {
                    int sum = start;
                    int ny = y;
                    int nx = x;
                    for (int k = 0; k < 3; k++)
                    {
                        ny = ny + dy[b0[k]];
                        nx = nx + dx[b0[k]];
                        if (ny >= N || nx >= M) break;
                        sum += map[ny][nx];
                    }
                    max_sum = max(max_sum, sum);
                }
                else if (g == 1)
                {
                    int sum = start;
                    int ny = y;
                    int nx = x;
                    for (int k = 0; k < 3; k++)
                    {
                        ny = ny + dy[b1[k]];
                        nx = nx + dx[b1[k]];
                        if (ny >= N || nx >= M) break;
                        sum += map[ny][nx];
                    }
                    max_sum = max(max_sum, sum);
                }
                else if (g == 2)
                {
                    int sum = start;
                    int ny = y;
                    int nx = x;
                    for (int k = 0; k < 3; k++)
                    {
                        ny = ny + dy[b2[k]];
                        nx = nx + dx[b2[k]];
                        if (ny >= N || nx >= M) break;
                        sum += map[ny][nx];
                    }
                    max_sum = max(max_sum, sum);
                }
                else if (g == 3)
                {
                    int sum = start;
                    int ny = y;
                    int nx = x;
                    for (int k = 0; k < 3; k++)
                    {
                        ny = ny + dy[b3[k]];
                        nx = nx + dx[b3[k]];
                        if (ny >= N || nx >= M) break;
                        sum += map[ny][nx];
                    }
                    max_sum = max(max_sum, sum);
                }
                else if (g == 4)
                {
                    int sum = start;
                    int ny = y;
                    int nx = x;
                    for (int k = 0; k < 3; k++)
                    {
                        ny = ny + dy[b4[k]];
                        nx = nx + dx[b4[k]];
                        if (ny >= N || nx >= M) break;
                        sum += map[ny][nx];
                    }
                    max_sum = max(max_sum, sum);
                }
                else if (g == 5)
                {
                    int sum = start;
                    int ny = y;
                    int nx = x;
                    for (int k = 0; k < 3; k++)
                    {
                        ny = ny + dy[b5[k]];
                        nx = nx + dx[b5[k]];
                        if (ny >= N || nx >= M) break;
                        sum += map[ny][nx];
                    }
                    max_sum = max(max_sum, sum);
                }
                else if (g == 6)
                {
                    int sum = start;
                    int ny = y;
                    int nx = x;
                    for (int k = 0; k < 3; k++)
                    {
                        ny = ny + dy[b6[k]];
                        nx = nx + dx[b6[k]];
                        if (ny >= N || nx >= M) break;
                        sum += map[ny][nx];
                    }
                    max_sum = max(max_sum, sum);
                }
                else if (g == 7)
                {
                    int sum = start;
                    int ny = y;
                    int nx = x;
                    for (int k = 0; k < 3; k++)
                    {
                        ny = ny + dy[b7[k]];
                        nx = nx + dx[b7[k]];
                        if (ny >= N || nx >= M) break;
                        sum += map[ny][nx];
                    }
                    max_sum = max(max_sum, sum);
                }
                else if (g == 8)
                {
                    int sum = start;
                    int ny = y;
                    int nx = x;
                    for (int k = 0; k < 3; k++)
                    {
                        ny = ny + dy[b8[k]];
                        nx = nx + dx[b8[k]];
                        if (ny >= N || nx >= M) break;
                        sum += map[ny][nx];
                    }
                    max_sum = max(max_sum, sum);
                }
            }
            max_val = max(max_val, max_sum);
            if (max_val == 210)
            {
                int gg = -1;
            }
        }
    }
}

int main() {
    input();

    solution();

    cout << max_val << endl;
}