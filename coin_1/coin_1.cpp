#pragma warning (disable: 4996)
#include <cstdio>
//memory 를 4MB만 이용해서??
int main() {

	int n, k;
	int coins[100];
	int ways[10001] = { 1, 0};

	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &coins[i]);
	}

	
		for (int j = 0; j < n; j++)
		{

			for (int i = 0; i <= k; i++)
			{
				if (i - coins[j] >= 0)
					ways[i] += ways[i - coins[j]];
			}
		}

	
	printf("%d\n", ways[k]);

	return 0;
}