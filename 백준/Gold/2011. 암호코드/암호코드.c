#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define SIZE 5001

int dp[SIZE];
char code[SIZE];
int size;

void input()
{
	scanf("%s", code);
	size = strlen(code);
}

void solution()
{
	int result = 0;
	dp[0] = dp[1] = 1;
	
	if (code[0] - '0' != 0)
	{
		for (int i = 2; i <= size; i++)
		{
			int a = code[i - 1] - '0';
			int b = code[i - 2] - '0';

			if (a == 0 && (b == 0 || b >= 3))
			{
				result = 0;
				break;
			}

			int num = b * 10 + a;
			dp[i] = dp[i - 1] + dp[i - 2];

			if (a == 0)
			{
				dp[i] -= dp[i - 1];
			}

			if (num < 10 || 26 < num)
			{
				dp[i] -= dp[i - 2];
			}

			dp[i] = dp[i] % 1000000;
			result = dp[i];
		}
		if (size == 1)
		{
			result = 1;
		}
	}

	printf("%d\n", result);

	return(0);
}


int main() {
	//freopen("sample_input.txt", "r", stdin);
	input();

	solution();

	return(0);
}