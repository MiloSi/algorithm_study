#include <iostream>
using namespace std;


int triangle[501][501];
inline int MAX(int a, int b) { return a > b ? a : b; }


int main() {
	int n;
	int x;
	int out;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> x;
			triangle[i][j] = x + MAX(triangle[i - 1][j], triangle[i - 1][j - 1]);
		}
	}

	out = 0;
	for (int i = 1; i <= n; i++)
	{
		if (out < triangle[n][i])
			out = triangle[n][i];
	}
	cout << out << endl;




	return 0;
}