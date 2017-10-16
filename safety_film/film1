#pragma warning (disable:4996)
#include <iostream>
#include <queue>
#include <memory.h>

typedef struct _NODE {
	int bits;
}Node;
using namespace std;
int arr[13][30];
int temp[13][30];
bool visited[1 << 26];
int k, tc, d, w, ans;

bool check() {
	int w1 = 0, b = 0;
	bool isOkay = false;

	for (int j = 0; j < w; j++) {
		w1 = b = 0;
		isOkay = false;
		for (int i = 0; i < d; i++) {
			if (temp[i][j] == 0) {
				w1++;
				b = 0;
			}
			else if (temp[i][j] == 1) {
				b++;
				w1= 0;
			}
			if (w1 == k || b == k) {
				isOkay = true;
				break;
			}
		}
		if (!isOkay) return false;
	}
	return true;
}


int bfs() {
	queue<Node> q;
	Node nd = { 0 };
	q.push(nd);
	int r = 0;
	while (q.size()) {
		int q_size = q.size();
		while (q_size--) {
			Node node2 = q.front();
			q.pop();
			int bits = 1;
			for (int i = 0; i < d; i++) {
				int bit1 = (bits & node2.bits);
				int bit2 = ((bits * 2) & node2.bits);


				if (bits == bit1) {
					for (int j = 0; j < w; j++) {
						temp[i][j] = 0;
					}
				}
				else if (bits * 2 ==  bit2) {
					for (int j = 0; j < w; j++) {
						temp[i][j] = 1;
					}
				}
				else {
					for (int j = 0; j < w; j++) 
						temp[i][j] = arr[i][j];
				}
				bits = bits << 2;
			}
			if (check()) return r;
		    bits = 1;
			for (int i = 0; i < d; i++) {
				if ((bits * 2 != ((bits * 2) & node2.bits)) && (bits != (bits & node2.bits))) {
					if (!visited[bits | node2.bits]) {
						visited[bits | node2.bits] = true;
						Node nd = { bits | node2.bits };
						q.push(nd);
					}
					if (!visited[bits * 2 | node2.bits]) {
						visited[bits * 2 | node2.bits] = true;

						Node nd = { bits * 2 | node2.bits };
						q.push(nd);
					}
				}
				bits = bits << 2;
			}

		}
		r++;
	}
	return r;
}
int main() {
	freopen("input.txt", "r", stdin);
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> d >> w >> k;

		memset(visited, 0, sizeof(visited));

		for (int i = 0; i < d; i++) {
			for (int j = 0; j < w; j++) {
				cin >> arr[i][j];
			}
		}
		ans = bfs();
		cout << "#" << t << " " << ans << endl;
	}

	return 0;
}
