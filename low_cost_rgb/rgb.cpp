
#pragma warning (disable : 4996)
#include <iostream>
using namespace std;

inline int min(int a, int b) {
	return a < b ? a : b;
}
inline int min(int a, int b, int c)
{
	return a < b ? (a < c ? a : c) : (b < c ? b : c);
}


int main() {
	int n;
	int r, g, b;
	int *rgb[3];
	int *max;

	cin >> n;

	
	for (int i = 0; i < 3; i++) {
		rgb[i] = new int[n];
	}
	cin >> rgb[0][0] >> rgb[1][0] >> rgb[2][0];
	for (int i = 1; i < n; i++) {
		cin >> r >> g >> b;
		rgb[0][i] = r + min(rgb[1][i-1], rgb[2][i-1]);
		rgb[1][i] = g + min(rgb[2][i - 1], rgb[0][i - 1]);
		rgb[2][i] = b + min(rgb[1][i - 1], rgb[0][i - 1]);
	}
	cout << min(rgb[0][n-1], rgb[1][n-1], rgb[2][n-1]) << endl;;
	
	for (int i = 0; i < 3; i++)
		delete[] rgb[i];

}