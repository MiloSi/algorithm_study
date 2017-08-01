#include <iostream>
#include <array>
using namespace std;

#define LOP(i,j,k) for(int i = j; i < k; i++)

inline int MAX(int a, int b) { return a > b ? a : b; }
inline int MAX(int a, int b, int c) {
	return MAX(a, MAX(b, c));
}
inline int MIN(int a, int b) { return a < b ? a : b; }
inline int MIN(int a, int b, int c) {
	return MIN(a, MIN(b, c));
}

typedef array<array<int, 3>, 2>  _Array;
_Array minArr;
_Array maxArr;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x, y, z;
	cin >> n;

	LOP(j, 0, 3) {
		cin >> x;
		maxArr[0][j] = minArr[0][j] = x;
	}

	LOP(i, 1, n) {
		cin >> x >> y >> z;
		maxArr[1][0] = x + MAX(maxArr[0][0], maxArr[0][1]);
		minArr[1][0] = x + MIN(minArr[0][0], minArr[0][1]);
		maxArr[1][1] = y + MAX(maxArr[0][0], maxArr[0][1], maxArr[0][2]);
		minArr[1][1] = y + MIN(minArr[0][0], minArr[0][1], minArr[0][2]);
		maxArr[1][2] = z + MAX(maxArr[0][1], maxArr[0][2]);
		minArr[1][2] = z + MIN(minArr[0][1], minArr[0][2]);

		LOP(j, 0, 3)
		{
			maxArr[0][j] = maxArr[1][j];
			minArr[0][j] = minArr[1][j];
		}

	}

	cout << MAX(maxArr[0][0], maxArr[0][1], maxArr[0][2]) << " " << MIN(minArr[0][0], minArr[0][1], minArr[0][2]) << endl;

	return 0;
}

