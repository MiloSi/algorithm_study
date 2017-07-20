#include <iostream>
#include <memory.h>
using namespace std;

int table[301][301];

int main() {
	int n, m;
	int v;

	int t;
	int x1, y1, x2, y2;
	int sum;

	cin >> n >> m;

	memset(table, 0, sizeof(table));

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> v;
			table[i][j] = table[i][j-1] + table[i-1][j] + v - table[i-1][j-1];
		}
	}

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> y1 >> x1 >> y2 >> x2;
		sum = table[y2][x2] - table[y2][x1-1] - table[y1-1][x2] + table[y1-1][x1-1];
		cout << sum << endl;
	}



	return 0;
}