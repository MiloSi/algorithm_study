#include <iostream>
using namespace std;
int n, m;

int people[101][101];


inline int MIN(int a, int b) {
	return a < b ? a : b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int y, x;
	int result = 1;
	int _Min = 100000, sum;


	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			people[i][j] = 101;
	for (int i = 0; i < m; i++) {
		cin >> y >> x;
		people[y][x] = people[x][y] =  1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (j == k)
					continue;
				people[j][k] = MIN(people[j][k],people[j][i] + people[i][k]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		sum = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j)
				continue;

			sum += people[i][j];
		}
		if (_Min > sum) {
			_Min = sum;
			result = i;
		}
	}

	cout << result << endl;
	return 0;
}