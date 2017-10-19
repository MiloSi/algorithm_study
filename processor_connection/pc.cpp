#pragma warning (disable:4996)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, t, ans, cores;
int arr[12][12];
int temp[12][12];

int xv[4] = { 0,1,0,-1 };
int yv[4] = { -1,0,1,0 };
typedef struct Node {
	int y, x;
	int length[4];
	int m;
}node;
vector<node> v;
node in(int a, int b) {
	node nd = { a, b };
	return nd;
}
bool search(int y, int x, int dir) {	
	int xf = x + xv[dir];
	int yf = y + yv[dir];
	while (xf >= 0 && xf < n && yf >= 0 && yf < n) {
		if (temp[yf][xf] == 1)
			return false;
		yf += yv[dir];
		xf += xv[dir];
	}
	return true;
}
void linking(int y, int x, int dir) {
	int xf = x + xv[dir];
	int yf = y + yv[dir];
	while (xf >= 0 && xf < n && yf >= 0 && yf < n) {
		temp[yf][xf] = 1;
		yf += yv[dir];
		xf += xv[dir];
	}
}
void dislinking(int y, int x, int dir) {
	int xf = x + xv[dir];
	int yf = y + yv[dir];
	while (xf >= 0 && xf < n && yf >= 0 && yf < n) {
		temp[yf][xf] = 0;
		yf += yv[dir];
		xf += xv[dir];
	}
	
}
void dfs(int idx, int sum, int core) {

	for (int i = idx; i < v.size(); i++) {
		if (v[i].m == 0) {
			dfs(i + 1, sum, core + 1);
		}
		else if (v[i].m == 655)
			dfs(i + 1, sum, core);

		else {
			for (int j = 0; j < 4; j++) {
				if (v[i].length[j] == -1) continue;
				if (search(v[i].y, v[i].x, j)) {
					linking(v[i].y, v[i].x, j);
					dfs(i + 1, sum + v[i].length[j], core + 1);
					dislinking(v[i].y, v[i].x, j);
				}
			}
		}
	}
	if (cores < core) {
		cores = core;
		ans = sum;
	}
	else if (cores == core) {
		if (ans > sum)
			ans = sum;
	}
}
int main() {
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n;
		cores = 0;
		ans = 5536;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
				temp[i][j] = arr[i][j];
				if (arr[i][j] == 1)
					v.push_back(in(i, j));
			}
		}
		for (int i = 0; i < v.size(); i++) {
			for (int j = i + 1; j < v.size(); j++) {
				if (v[i].x == v[j].x) {
					if (v[i].y < v[j].y) {
						v[i].length[2] = -1;
						v[j].length[0] = -1;
					}
					else {
						v[i].length[0] = -1;
						v[j].length[2] = -1;
					}
				}
				else if (v[i].y == v[j].y) {
					if (v[i].x < v[j].x) {
						v[i].length[1] = -1;
						v[j].length[3] = -1;
					}
					else {
						v[i].length[3] = -1;
						v[j].length[1] = -1;
					}
				}
			}
			if (v[i].length[0] != -1) v[i].length[0] = v[i].y;
			if (v[i].length[1] != -1) v[i].length[1] = n - v[i].x - 1;
			if (v[i].length[2] != -1) v[i].length[2] = n - v[i].y - 1;
			if (v[i].length[3] != -1) v[i].length[3] = v[i].x;

			v[i].m = 655;
			for (int j = 0; j < 4; j++) {
				if (v[i].m > v[i].length[j] && v[i].length[j] != -1) v[i].m = v[i].length[j];
			}
		}
		dfs(0, 0, 0);

		cout << "#" << tc << " " << ans << endl;
		v.clear();
	}
	return 0;
}
