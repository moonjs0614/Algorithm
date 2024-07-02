#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int N;
int arr[50][9];
int batting_order[9];
bool selected[10];
int maxPoint = 0;

void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> arr[i][j];
		}
	}
}

void sumscore()
{
	int score = 0;
	int st = 0;
	bool next;
	bool base[4];

	for (int i = 0; i < N; i++)
	{
		int outcnt = 0;
		next = false;
		memset(base, false, sizeof(base));

		while (true)
		{
			for (int j = st; j < 9; j++)
			{
				int batter = arr[i][batting_order[j]];

				if (batter == 0)
				{
					outcnt++;
				}
				else if (batter == 1)
				{
					for (int k = 3; k > 0; k--)
					{
						if (base[k] == true)
						{
							if (k == 3)
							{
								score++;
								base[k] = false;
							}
							else
							{
								base[k + 1] = true;
								base[k] = false;
							}
						}
					}
					base[1] = true;
				}
				else if (batter == 2)
				{
					for (int k = 3; k > 0; k--)
					{
						if (base[k] == true)
						{
							if (k >= 2)
							{
								score++;
								base[k] = false;
							}
							else if (k == 1)
							{
								base[k + 2] = true;
								base[k] = false;
							}
						}
					}
					base[2] = true;
				}
				else if (batter == 3)
				{
					for (int k = 3; k > 0; k--)
					{
						if (base[k] == true)
						{
							score++;
							base[k] = false;
						}
					}
					base[3] = true;
				}
				else if (batter == 4)
				{
					for (int k = 3; k > 0; k--)
					{
						if (base[k] == true)
						{
							score++;
							base[k] = false;
						}
					}
					score++;
				}

				if (outcnt == 3)
				{
					st = j + 1;

					if (st == 9) st = 0;
					next = true;
					break;
				}
			}

			if (next == true) break;
			st = 0;
		}
	}

	maxPoint = max(maxPoint, score);
}

void dfs(int level)
{
	if (level == 9)
	{
		sumscore();
		return;
	}

	for (int i = 0; i < 9; i++)
	{
		if (selected[i] == true) continue;
		
		selected[i] = true;
		batting_order[i] = level;

		dfs(level + 1);

		selected[i] = false;
	}
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	input();

	selected[3] = true;
	batting_order[3] = 0;
	
	dfs(1);

	cout << maxPoint << endl;
}