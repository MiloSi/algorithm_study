#include <iostream>
#include <memory.h>

using namespace std;

int stairs[301][2];

inline int MAX(int a, int b) {
	return a > b ? a : b;
}

int main() {
	
	int n;
	int x;
	cin >> n;

	//재활용 안하면 쓸 모 없어
	memset(stairs, 0, sizeof(stairs));
	cin >> stairs[1][0];
	stairs[1][1] = stairs[1][0];
	for (int i = 2; i <= n; i++) {
		cin >> x;

		stairs[i][0] = x + stairs[i - 1][1];
		stairs[i][1] = x + MAX(stairs[i - 2][0], stairs[i - 2][1]);
	}

	cout << MAX(stairs[n][0], stairs[n][1]) << endl;

	return 0;

}