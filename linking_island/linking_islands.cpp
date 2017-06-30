#pragma warning (disable : 4996)
#include <cstdio>
#include <memory.h>

int Answer;
int w;
int min;

inline int abs(int a, int b)
{
	if (a > b)
		return a - b;
	else
		return b - a;
}

//void map(long **p, long *d, int *visited, int cur, int n, int prv)
//{
//	visited[cur] = 1;
//	for (int i = 0; i < n; i++)
//	{
//		if (visited[i] == 0)
//			break;
//
//		if (i == n - 1)
//		{
//			if (min > w)
//				min = w;
//			visited[cur] = 0;
//			return;
//		}
//	}
//	if (d[cur] == 0) {
//		visited[cur] = 0;
//		return;
//	}
//	d[cur]--;
//
//	for (int i = 0; i < n; i++)
//	{
//		if (cur == i || d[i] == 0 || i == prv)
//			continue;
//		
//		w += p[cur][i];
//		visited[i] = 1;
//		d[i]--;
//		map(p, d, visited, i, n, cur);
//		d[i]++;
//		visited[i] = 0;
//		w -= p[cur][i];
//	}
//	d[cur]++;
//	visited[cur] = 0;
//}


void map(long **p, long *d, int *visited, int cur, int n, int prv, int k)
{
	for (int i = 0; i < n; i++)
	{
		if (visited[i] == 0)
			break;
		if (i == n - 1)
		{
			if (min > w)
				min = w;
			return;
		}
	}
	if (k == n || d[cur] == 0)
		return;

	for (int i = 0; i < n; i++)
	{
		if (cur == i || i == prv || d[i] <= 0)
			continue;

		d[cur]--;
		d[i]--;
		visited[cur]++;
		visited[i]++;
		w += p[cur][i];

		map(p, d, visited, i, n, cur, k+1);

		visited[cur]--;
		visited[i]--;
		w -= p[cur][i];
		d[cur]++;
		d[i]++;
	}

}

int main(void)
{
	int T, test_case;
	int n;
	long **p;
	int *visited;
	long *d;

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{

		scanf("%d", &n);
		w = 0;
		min = 0x7fffffff;
		p = new long*[n];
		for (int i = 0; i < n; i++)
		{
			p[i] = new long[n];
			memset(p[i], 0, sizeof(long) * n);
		}
		d = new long[n];
		visited = new int[n];
		memset(d, 0, sizeof(long) * n);
		memset(visited, 0, sizeof(int) * n);

		for (int i = 0; i < n; i++)
		{
			scanf("%ld %ld", &p[i][i], &d[i]);
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = i+1; j < n; j++)
			{
				p[i][j] = abs(p[i][i], p[j][j]);
				p[j][i] = p[i][j];
			}
		}

		map(p, d, visited, 0, n, 0, 1);
		

	
		printf("Case #%d\n", test_case + 1);
		if (min == 0x7fffffff)
			printf("-1\n");
		else
			printf("%d\n", min);


		delete[] d;
		delete[] visited;
		for (int i = 0; i < n; i++)
			delete[] p[i];
		delete[] p;
	}

	return 0;
}