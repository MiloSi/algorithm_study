#include <iostream>
using namespace std;
int arr[501];
int dp[501];
int main() {
	int n;
	int max = 0;
	int x, y;
	cin >> n;
	while (n--) {
		cin >> x >> y;
		arr[x] = y;
	}
	for (int i = 1; i <= 500; i++) {
		if (arr[i] == 0) continue;
		for (int j = i; j <= 500; j++) {
			if (arr[j] == 0) continue;
			if (arr[i] > arr[j]) {

			}
		}
	}
	return 0;
}