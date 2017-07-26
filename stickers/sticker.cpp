#pragma warning (disable : 4996)
#include <cstdio>

int stickers[2][100001] = { 0, };


inline int MAX(int a, int b)
{

	return a > b ? a : b;

}


int main() {
	int n, t;
	
	scanf("%d", &t);

	for (int testcase = 0; testcase < t; testcase++)
	{
		scanf("%d", &n);

		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= n; j++)
			{
				scanf("%d", &stickers[i][j]);
			}
		}
	

		for (int j = 2; j <= n; j++)
		{
			stickers[0][j] = stickers[0][j] + MAX(stickers[1][j - 1], MAX(stickers[0][j - 2], stickers[1][j - 2]));
			stickers[1][j] = stickers[1][j] + MAX(stickers[0][j - 1], MAX(stickers[0][j - 2], stickers[1][j - 2]));
		}


		printf("%d\n", MAX(stickers[0][n], stickers[1][n]));
	}





	return 0;
}

