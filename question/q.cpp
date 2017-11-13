#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[20][20];
bool visited[20];
int n, m;
int ans = 0;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i][j] != arr[j][i]) {
				cout << -1 << endl;
				return 0;
			}
		}
	}
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			bool isOkay = true;
			for (int k = 0; k < n; k++) {
				if (i == k) continue;
				if (j == k) continue;
				if (arr[i][j] > arr[i][k] + arr[k][j]) {
					cout << -1 << endl;
					return 0;
				}

				if (arr[i][j] == arr[i][k] + arr[k][j]) {
					isOkay = false;
					break;
				}
			}
			if (isOkay) ans += arr[i][j];
		}
	}
	cout << ans << endl;
	return 0;
}
