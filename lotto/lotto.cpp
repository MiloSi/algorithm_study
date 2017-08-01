#include <iostream>
#include <array>
#include <queue>
using namespace std;
array<int, 50> arr;

int n;
void dfs(int index, int s, queue<int> q) {
	q.push(arr[index]);
	if (q.size() == 6) {
		while (q.size()) {
			cout << q.front() << " ";
			q.pop();
		}
		cout << endl;
		return;
	}
	for (int i = index + 1; i < n; i++) {
		if (n - i < s)
			return;
		dfs(i, s-1, q);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	while (n != 0) {
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		for (int i = 0; i < n; i++) {
			if (n - i < 6)
				break;
			queue<int> q;
			dfs(i, 5, q);
		}
		cout << endl;
		cin >> n;
	}
	return 0;
}