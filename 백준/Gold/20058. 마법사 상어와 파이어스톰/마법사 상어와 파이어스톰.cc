#include <cstdio>
#include <algorithm>
#define pow2(x) (1<<(x))
using namespace std;

int n, q, s;
int a[129][129], dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
bool visit[129][129];

bool safe(int x, int y) { return x >= 0 && x < n&& y >= 0 && y < n; }

void melting() {
	bool check[129][129] = { false };
	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++) {
			if (!a[i][j])continue;
			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int nx = j + dx[k], ny = i + dy[k];
				if (safe(nx, ny)&&a[ny][nx]>0)cnt++;
			}
			if (cnt < 3)check[i][j]=true;
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (check[i][j])a[i][j]--;
}

void rotate(int r, int c, int l) {
	int temp[129][129];
	for (int i = 0; i < l; i++)
		for (int j = 0; j < l; j++) {
			temp[i][j] = a[r + l - 1 - j][c + i];
		}

	for (int i = 0; i < l; i++)
		for (int j = 0; j < l; j++) {
			a[r + i][c + j] = temp[i][j];
		}
}

void divide(int r, int c, int l) {
	if (l == pow2(s)) {
		rotate(r, c, l);
		return;
	}
	divide(r, c, l >> 1);
	divide(r + (l >> 1), c, l >> 1);
	divide(r, c + (l >> 1), l >> 1);
	divide(r + (l >> 1), c + (l >> 1), l >> 1);
}

int dfs(int x, int y) {
	if (visit[y][x])return 0;
	visit[y][x] = true;

	int cnt = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (!safe(nx,ny)|| visit[ny][nx] || a[ny][nx] == 0)continue;
		cnt += dfs(nx, ny);
	}
	return cnt;
}

int main() {
	scanf("%d%d", &n, &q);
	n = pow2(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)scanf("%d", &a[i][j]);
	while (q--) {
		scanf("%d", &s);
		divide(0, 0, n);
		melting();
	}
	int sum = 0,m=0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			sum += a[i][j];
			if (a[i][j]&&!visit[i][j]) {
				int cnt = dfs(j, i);
				m = max(cnt, m);
			}
		}
	printf("%d\n%d", sum, m);
	return 0;
}