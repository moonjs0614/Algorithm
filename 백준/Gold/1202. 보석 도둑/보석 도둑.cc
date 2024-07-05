#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int N, K;
long long answer = 0;
int idx = 0;
struct jewel
{
	int weight;
	long long value;
	int num;
};
bool cmp_weight (jewel a, jewel b)
{
	return a.weight < b.weight;
}
struct cmp_value
{
	bool operator() (jewel a, jewel b)
	{
		return a.value < b.value;
	}
};
vector<jewel> jewels;
vector<int> bags;
priority_queue<jewel, vector<jewel>, cmp_value> pq;

void input()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		jewel temp;
		cin >> temp.weight >> temp.value;
		temp.num = i;
		jewels.push_back(temp);
	}

	for (int i = 0; i < K; i++)
	{
		int temp;
		cin >> temp;
		bags.push_back(temp);
	}
}

void solution()
{
	sort(bags.begin(), bags.end()); // 가방을 수용치 기준 오름차순 정렬
	sort(jewels.begin(), jewels.end(), cmp_weight); // 보석을 무게 기준 오름차순 정렬

	// 수용치가 가장 낮은 가방부터 순서대로 채우기
	for (int i = 0; i < K; i++)
	{
		for (int j = idx; j < jewels.size(); j++)
		{
			if (jewels[j].weight > bags[i]) break;
			pq.push(jewels[j]);
			idx++;
		}

		if (pq.empty()) continue;
		answer += pq.top().value;
		pq.pop();
	}
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	input();

	solution();

	cout << answer << endl;
}