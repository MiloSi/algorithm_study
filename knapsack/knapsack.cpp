#include <iostream>


int map[100][10001];
int weight[101];
int value[101];

using namespace std;

inline int MAX(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int n, k;
	int v, w;
	int ans = 0;

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> v >> w;
		value[i] = v;
		weight[i] = w;
	}
	

	//d[i][j] = MAX(d[i-1][j - w[i]] + v[i], d[i-1][j])
	for (int i = 1; i <= n; i++)
	{

		for (int j = 0; j <= k; j++)
		{
			if (weight[i] <= j)
				map[i][j] = MAX(map[i - 1][j], map[i - 1][j - weight[i]] + value[i]);
			else
				map[i][j] = map[i-1][j];	
		}
	}
	for (int i = 0; i <= k; i++) {
		ans = ans > map[n][i] ? ans : map[n][i];
	}

	cout << ans << endl;



}