#include <iostream>
using namespace std;
int arr[20];
int n, m, result;
void backtracking(int pos, int sum) {
	if (sum == m && pos != -1) {
		result++;
	}
	for (int i = pos+1; i < n; i++) {
		backtracking(i, sum + arr[i]);
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	backtracking(-1,0);
	cout << result << endl;
	system("pause");
	return 0;
}