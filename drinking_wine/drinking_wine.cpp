#include <iostream>
#include <memory.h>
using namespace std;


inline int MAX(int a, int b){return a > b ? a : b;}
int main() {

	int wine[10001][2];
	int n;
	int x;

	cin >> n;

	memset(wine, 0, sizeof(wine));


	if (n <= 2) {
		for (int i = 1; i <= n; i++)
		{
			cin >> wine[i][0];
			wine[i][0] += wine[i - 1][0];
		}
		cout << wine[n][0] << endl;
	}
	else {
		cin >> wine[1][1];

		for (int i = 2; i <= n; i++)
		{
			cin >> x;
			wine[i][0] = MAX(x + wine[i - 1][1], wine[i-1][0]);
			wine[i][1] = MAX(x + wine[i - 2][0], x + wine[i - 2][1]);
		}

		cout << MAX(wine[n][0], wine[n][1]) << endl;
	}

	return 0;
}