#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

#define MAX 100001
int N;
int arr[MAX];
bool visited[MAX];
vector<int> v[MAX];

void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}
}

void dfs(int t)
{
	visited[t] = true;

	for (int i = 0; i < v[t].size(); i++)
	{
		int next = v[t][i];

		if (!visited[next])
		{
			arr[next] = t;
			dfs(next);
		}
	}
}

void solution()
{
	dfs(1);

	for (int i = 2; i <= N; i++)
	{
		cout << arr[i] << "\n";
	}
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(1);

	for (int i = 2; i <= N; i++)
	{
		cout << arr[i] << "\n";
	}
}