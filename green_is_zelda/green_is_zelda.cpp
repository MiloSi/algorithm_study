#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int ans;
int n, tc = 0;
int arr[125][125];
int dp[125][125];
bool visited[125][125];
int counts[125][125];
typedef struct _NODE {
	int idx;
	int w;
}node;
struct myrule {
	bool operator()(node a, node b) {
		return a.w > b.w;
	}
};
int xv[4] = { 0,1,0,-1 };
int yv[4] = { -1,0,1,0 };
void dijkstra() {
	node nd = { 0, arr[0][0] };
	dp[0][0] = arr[0][0];
	int v_number = n*n -1;
	priority_queue<node, vector<node>, myrule> pq;
	pq.push(nd);
	while (pq.size() && v_number >= 0) {
		int y = pq.top().idx / n;
		int x = pq.top().idx % n;
		int w = pq.top().w;
		pq.pop();
		if (visited[y][x]) continue;
		visited[y][x] = true;
		v_number--;
		for (int i = 0; i < 4; i++) {
			int xf = x + xv[i];
			int yf = y + yv[i];

			if (xf < 0 || xf > n - 1 || yf < 0 || yf > n - 1) continue;
			if (!visited[yf][xf]) {
				if (dp[yf][xf] > dp[y][x] + arr[yf][xf]) {
					dp[yf][xf] = dp[y][x] + arr[yf][xf];
					nd = { yf * n + xf, w + arr[yf][xf] };
					pq.push(nd);
					counts[yf][xf] = y * n + x;
				}
			}
		}
	}
	return;
}
const int IN_MAX = 0x5ffffff;
int main() {
	cin >> n;

	while (n != 0) {
		tc++;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
				visited[i][j] = false;
				dp[i][j] = IN_MAX;
				counts[i][j] = 0;
			}
		}
		dijkstra();
		int y = n - 1, x = n - 1;
		ans = arr[n-1][n-1];
		while (y*n+x != 0) {

			int f = counts[y][x];
			y = f / n;
			x = f % n;
			ans += arr[y][x];
		}
		cout << "Problem " << tc << ": " << ans << endl;
		cin >> n;
	}
	return 0;
}

