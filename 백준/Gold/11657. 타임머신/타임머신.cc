#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

#define MAX 501
#define INF 987654321;

int N, M;
long long dist[MAX];
struct BUS
{
	int st, en, cost;
};
vector<BUS> v;

void input()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		v.push_back({ a, b, c });
	}
}

void bellman()
{
	dist[1] = 0;

	for (int i = 1; i <= N - 1; i++)
	{
		for (int j = 0; j < v.size(); j++)
		{
			int from = v[j].st;
			int to = v[j].en;
			int cost = v[j].cost;

			if (dist[from] == 987654321) continue;

			if (dist[to] > dist[from] + cost)
			{
				dist[to] = dist[from] + cost;
			}
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		int from = v[i].st;
		int to = v[i].en;
		int cost = v[i].cost;

		if (dist[from] == 987654321) continue;
		
		if (dist[to] > dist[from] + cost)
		{
			cout << -1 << endl;
			return;
		}
	}

	for (int i = 2; i <= N; i++)
	{
		if (dist[i] == 987654321)
		{
			cout << -1 << endl;
		}
		else
		{
			cout << dist[i] << endl;
		}
	}
}

void solution()
{
	for (int i = 1; i <= N; i++)
	{
		dist[i] = INF;
	}

	bellman();
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	input();

	solution();
}