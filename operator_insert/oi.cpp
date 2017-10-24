#include <iostream>
using namespace std;
int arr[12];
int oper[4];
int n;
int _max, _min;
void solution(int idx, int ans) {
	if (idx == n) {
		if (_max < ans) _max = ans;
		if (_min > ans) _min = ans;
		return;
	}
	if (oper[0] >= 1) {

		oper[0]--;
		solution(idx + 1, ans + arr[idx]);
		oper[0]++;
	}
	if (oper[1] >= 1) {
		oper[1]--;
		solution(idx + 1, ans - arr[idx]);
		oper[1]++;
	}
	if (oper[2] >= 1) {
		oper[2]--;
		solution(idx + 1, ans * arr[idx]); 
		oper[2]++;
	}
	if (oper[3] >= 1) {
		oper[3]--;
		solution(idx + 1, ans / arr[idx]);
		oper[3]++;
	}
}
int main() {
	cin >> n;
	_max = -0x6fffffff;
	_min =0x6fffffff;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 4; i++)
		cin >> oper[i];

	solution(1, arr[0]);

	cout << _max << endl << _min << endl;
	return 0;
}
