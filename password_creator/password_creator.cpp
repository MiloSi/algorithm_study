#include <iostream>
#include <queue>
using namespace std;
int arr[8];
int main() {
	int t, x;
	queue<int> q;
	for (int t = 1; t <= 10; t++) {
		cin >> t;
		for (int i = 0; i < 8; i++) {
			cin >> x;
			q.push(x);
		}
		int s = 1;
		while (true) {
			int x = q.front();
			q.pop();
			x -= s;
			if (x <= 0) {
				q.push(0);
				break;
			}
			q.push(x);
			s++;
			if (s > 5) s = 1;
		}
		cout << "#" << t;
		while (q.size()) {
			cout << " " << q.front();
			q.pop();
		}
		cout << endl;
	}
	return 0;
}