#include <iostream>
using namespace std;


int table[50] = { 0, };
int s = 0;

inline int ABS(int a)
{
	return a > 0 ? a : -a;
}
inline int MIN(int a, int b) {
	return a < b ? a : b;
}
int main() {
	int n, m;
	int t;
	int c = 1;
	int k = 0;
	int left;
	int right;
	int cost = 0;

	cin >> n >> m;
 	for (int i = 0; i < m; i++)
	{
		cin >> t;
		right = ABS(c - t);
		left = ABS(c + (n - t));
		for (int j = 0; j < s; j++) {
			if (c < t) {
				if (c < table[j] && table[j] < t)
					right--;
				else
					left--;
			}
			else {
				if (t < table[j] && table[j] < c)
					right--;
				else
					left--;
			}
		}
		cost += MIN(right, left);
		table[s++] = t;
		while (k != s)
		{
			if (t == table[k]) {
				t++;
				if (t == n)
					t = 1;

				k = 0;
			}
			else {
				k++;
			}
		}
		c = t;
	}

	cout << cost << endl;

	return 0;
}