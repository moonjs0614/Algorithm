#include <cstdio>

int N, a,num[100001],cnt;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a);
		num[a] = i;
	}
	for (int i = 1; i < N; i++) {
		if (num[i] > num[i + 1]) cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}