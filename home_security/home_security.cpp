#pragma warning (disable:4996)
#include <iostream>
#include <queue>
using namespace std;
int arr[20][20];
bool visited[20][20];

typedef struct _Node {
	int y, x;
}Node;
int tc,n, m, ans;

int xv[4] = { 0,1,0,-1 };
int yv[4] = { 1,0,-1,0 };


void init() {
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) visited[i][j] = false;
}

void getValue(int y, int x) {
	queue<Node> q;
	int w = 1;
	int cost = 1;
	int value = 0;

	init();

	if (arr[y][x] == 1) value = 1;
	if (cost < value * m) {
		if(ans < 1)
			ans = 1;
	}
	Node nd = { y,x };
	visited[y][x] = 1;
	q.push(nd);
	while (q.size()) {
		int q_size = q.size();
		while (q_size--) {
			int y1 = q.front().y;
			int x1 = q.front().x;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int yf = y1 + yv[i];
				int xf = x1 + xv[i];

				if (yf < 0 || yf > n - 1 || xf < 0 || xf > n - 1) continue;
				if (!visited[yf][xf]) {
					visited[yf][xf] = 1;
					if (arr[yf][xf] == 1) {
						value++;
					}
					nd = { yf,xf };
					q.push(nd);
				}
			}
		}
		cost += w * 4;
		w++;
		if (value * m > cost) {
			if (ans < value) ans = value;
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	cin >> tc;
	for (int testcase = 1; testcase <= tc; testcase++) {
		ans = 0;
		cin >> n >> m;
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> arr[i][j];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				getValue(i, j);

		cout << "#" << testcase << " " << ans << endl;
	}
	return 0;
}
