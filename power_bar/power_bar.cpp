#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX_NUM = 101;
int arr[100];
int sequence[101];
bool isInput[101]; 
int table[101];
queue<int> q[101];
int getLaterIndex(int n) {
	int idx = 0, maxValue = 0;
	for (int i = 0; i < n; i++) {
		if (maxValue < q[table[i]].front()) {
			maxValue = q[table[i]].front();
			idx = i;
		}
	}
	return idx;
}
int tableSize = 0;
int main() {
	int n, m, result = 0;
	cin >> n >> m;	
	for (int i = 0; i < m; i++) {
		cin >> arr[i];
		q[arr[i]].push(i);
		sequence[arr[i]] ++;
	}
	for (int i = 1; i <= m; i++) {
		q[i].push(MAX_NUM);
	}
	isInput[arr[0]] = true;
	table[tableSize++] = arr[0];
	q[arr[0]].pop();
	for (int i = 1; i < m; i++) {
		if (isInput[arr[i]]) {
			q[arr[i]].pop();
			continue;
		}
		if (tableSize == n) {
			int idx = getLaterIndex(n);
			isInput[table[idx]] = false;
			isInput[arr[i]] = true;
			table[idx] = arr[i];
			result++;
		}
		else {
			isInput[arr[i]] = true;
			table[tableSize++] = arr[i];
		}
		q[arr[i]].pop();
	}
	cout << result << endl;
	system("pause");
	return 0;
}