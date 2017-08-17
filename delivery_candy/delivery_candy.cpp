#include <iostream>
using namespace std;
int arr[5001];
int main() {
	int n;
	int x, y;
	cin >> n;
	arr[3] = 1;
	arr[5] = 1;

	for (int i = 6; i <= n; i++) {
		x = arr[i - 3]; 
		y = arr[i - 5];
		if (x == 0) x = 5001;
		if (y == 0) y = 5001;
		arr[i] = x < y ? x : y;
		if (arr[i] != 5001) arr[i]++;
	}
	if (arr[n] == 0 || arr[n] == 5001) cout << -1 << endl;
	else cout << arr[n] << endl;
	return 0;
}