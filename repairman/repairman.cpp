#include <iostream>
#include <algorithm>
using namespace std;
int arr[1001];
int main() {
	int n, l, result, term;
	cin >> n >> l;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	result = 1;

	term = 1;
	for (int i = 1; i < n; i++) {
		term += arr[i] - arr[i-1];
		if (term > l) {
			result++;
			term = 1;
		}
	}
	cout << result << endl;
	return 0;
}