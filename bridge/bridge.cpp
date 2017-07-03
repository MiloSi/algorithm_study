#pragma warning (disable :4996)
#include <cstdio>

int main()
{
	int n;
	int m;
	long long table[30][30] = { 0, };
	scanf("%d %d", &n, &m);
	
	table[0][0] = 1;
	for (int i = 1; i <= m; i++)
	{
		table[i][0] = 1;
		for (int j = 0; j <= i; j++)
		{
			if (j == 0)
				table[i][j] = 1;
			else
				table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % 10000000006;
		}
	}
	
	printf("%lld\n", table[m][n]);
}
