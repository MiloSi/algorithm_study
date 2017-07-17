#include <iostream>

using namespace std;

int main() {
	int n, x, y;
	int r = 0;
	cin >> n >> x >> y;


	while (x != y) {
		x = (x + 1) >> 1;
		y = (y + 1) >> 1;
		r++;

		if (x == y) break;
	}
	cout << r << endl;
}