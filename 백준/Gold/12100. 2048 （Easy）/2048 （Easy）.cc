#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> map(20, vector<int>(20, 0));
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int max_ans = 0;
vector<int> history;

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

void move(int dir, vector<vector<int>>& v)
{
	// 합쳐짐 여부를 체크하는 2차원 벡터
	vector<vector<int>> check(20, vector<int>(20, 0));

	// 상
	if (dir == 0)
	{
		// 횡으로 돌면서 열마다 처리
		for (int col = 0; col < N; col++)
		{
			// 이동할 칸 수
			int cnt = 0;

			for (int row = 0; row < N; row++)
			{
				// 0(빈칸)을 만나면 이동할 칸 수 증가
				if (v[row][col] == 0)
				{
					cnt++;
				}
				// 0(빈칸)이 아니면 이동
				else if (v[row][col] != 0 && cnt != 0)
				{
					// 이동
					v[row - cnt][col] = v[row][col];
					v[row][col] = 0;

					// 만약 합칠 수 있으면 합치기
					if (row - cnt > 0 && check[row - cnt - 1][col] == 0 && v[row - cnt - 1][col] == v[row - cnt][col])
					{
						v[row - cnt - 1][col] *= 2;
						v[row - cnt][col] = 0;
						check[row - cnt - 1][col] = 1;
						cnt++;
					}
				}
				// 이동할 칸은 없지만 합칠수는 있을 때
				else if (row > 0 && v[row][col] == v[row - 1][col] && check[row - 1][col] == 0)
				{
					v[row - cnt - 1][col] *= 2;
					v[row - cnt][col] = 0;
					check[row - cnt - 1][col] = 1;
					cnt++;
				}
			}
		}
	}
	// 하
	else if (dir == 1)
	{
		// 횡으로 돌면서 열마다 처리
		for (int col = 0; col < N; col++)
		{
			// 이동할 칸 수
			int cnt = 0;
			
			for (int row = N - 1; row > -1; row--)
			{
				// 0(빈칸)을 만나면 이동할 칸 수 증가
				if (v[row][col] == 0)
				{
					cnt++;
				}
				// 0(빈칸)이 아니면 이동
				else if (v[row][col] != 0 && cnt != 0)
				{
					// 이동
					v[row + cnt][col] = v[row][col];
					v[row][col] = 0;

					// 만약 합칠 수 있으면 합치기
					if (row + cnt < N - 1 && check[row + cnt + 1][col] == 0 && v[row + cnt + 1][col] == v[row + cnt][col])
					{
						v[row + cnt + 1][col] *= 2;
						v[row + cnt][col] = 0;
						check[row + cnt + 1][col] = 1;
						cnt++;
					}
				}
				// 이동할 칸은 없지만 합칠수는 있을 때
				else if (row < N - 1 && v[row][col] == v[row + 1][col] && check[row + 1][col] == 0)
				{
					v[row + cnt + 1][col] *= 2;
					v[row + cnt][col] = 0;
					check[row + cnt + 1][col] = 1;
					cnt++;
				}
			}
		}
	}
	// 좌
	else if (dir == 2)
	{
		// 열마다 돌면서 횡으로 처리 (좌 -> 우)
		for (int row = 0; row < N; row++)
		{
			// 이동할 칸 수
			int cnt = 0;

			for (int col = 0; col < N; col++)
			{
				// 0(빈칸)을 만나면 이동할 칸 수 증가
				if (v[row][col] == 0)
				{
					cnt++;
				}
				// 0(빈칸)이 아니면 이동
				else if (v[row][col] != 0 && cnt != 0)
				{
					// 이동
					v[row][col - cnt] = v[row][col];
					v[row][col] = 0;

					// 만약 합칠 수 있으면 합치기
					if (col - cnt > 0 && check[row][col - cnt - 1] == 0 && v[row][col - cnt - 1] == v[row][col - cnt])
					{
						v[row][col - cnt - 1] *= 2;
						v[row][col - cnt] = 0;
						check[row][col - cnt - 1] = 1;
						cnt++;
					}
				}
				// 이동할 칸은 없지만 합칠수는 있을 때
				else if (col > 0 && v[row][col] == v[row][col - 1] && check[row][col - 1] == 0)
				{
					v[row][col - cnt - 1] *= 2;
					v[row][col - cnt] = 0;
					check[row][col - cnt - 1] = 1;
					cnt++;
				}
			}
		}
	}
	// 우
	else if (dir == 3)
	{
		// 열마다 돌면서 횡으로 처리 (우 -> 좌)
		for (int row = 0; row < N; row++)
		{
			// 이동할 칸 수
			int cnt = 0;

			for (int col = N - 1; col > -1; col--)
			{
				// 0(빈칸)을 만나면 이동할 칸 수 증가
				if (v[row][col] == 0)
				{
					cnt++;
				}
				// 0(빈칸)이 아니면 이동
				else if (v[row][col] != 0 && cnt != 0)
				{
					// 이동
					v[row][col + cnt] = v[row][col];
					v[row][col] = 0;

					// 만약 합칠 수 있으면 합치기
					if (col + cnt > 0 && check[row][col + cnt + 1] == 0 && v[row][col + cnt + 1] == v[row][col + cnt])
					{
						v[row][col + cnt + 1] *= 2;
						v[row][col + cnt] = 0;
						check[row][col + cnt + 1] = 1;
						cnt++;
					}
				}
				// 이동할 칸은 없지만 합칠수는 있을 때
				else if (col < N - 1 && v[row][col] == v[row][col + 1] && check[row][col + 1] == 0)
				{
					v[row][col + cnt + 1] *= 2;
					v[row][col + cnt] = 0;
					check[row][col + cnt + 1] = 1;
					cnt++;
				}
			}
		}
	}
}

int find_max_val(vector<vector<int>>& v)
{
	int max_val = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			max_val = max(max_val, v[i][j]);
		}
	}

	return max_val;
}

void dfs(int level, vector<vector<int>> &v)
{
	if (level == 5)
	{
		int max_val_in_v = find_max_val(v);
		max_ans = max(max_val_in_v, max_ans);

		return;
	}

	for (int i = 0; i < 4; i++)
	{
		// copy_map
		vector<vector<int>> copy_map(20, vector<int> (20, 0));
		copy(v.begin(), v.end(), copy_map.begin());

		move(i, v);
		history.push_back(i);

		int de = -1;

		dfs(level + 1, v);
		copy(copy_map.begin(), copy_map.end(), v.begin());
		history.pop_back();
	}
}

void solution()
{
	dfs(0, map);

	cout << max_ans;
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	input();
	
	solution();
}