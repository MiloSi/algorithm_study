#include <iostream>
#include <vector>
#include <queue>
using namespace std;
char map[50][50];
int islands[50][50];
bool visited[50][50];
int n, m;
int ans[2500];
int mMax = 0;
vector<vector<int>> tree;
vector<int> seq;

void setIslands(int num, int y, int x) {
	queue<int> q;
	int xv[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
	int yv[8] = { -1,-1, 0, 1, 1, 1, 0, -1 };
	q.push(y*m + x);
	islands[y][x] = num;
	visited[y][x] = true;

	while (q.size()) {
		int coord = q.front();
		q.pop();
		y = coord / m;
		x = coord % m;
		for (int i = 0; i < 8; i++) {
			int ym = y + yv[i];
			int xm = x + xv[i];
			if (xm == -1 || xm == m || ym == -1 || ym == n) continue;
			if (!visited[ym][xm] && map[ym][xm] == 'x') {
				visited[ym][xm] = true;
				islands[ym][xm] = num;
				q.push(ym * m + xm);
			}
		}
	}
}
void setTree(int num, int y, int x) {
	queue<int> q;
	int parents = num;
	int xv[4] = { 0,  1,  0, -1 };
	int yv[4] = { -1, 0,  1, 0 };
	q.push(y * m + x);
	visited[y][x] = true;
	while (q.size()) {
		int coord = q.front();
		q.pop();
		y = coord / m;
		x = coord % m;
		if (x == 0 || x == m - 1 || y == 0 || y == n - 1) {
			tree[0].push_back(num);
			return;
		}
		for (int i = 0; i < 4; i++) {
			int ym = y + yv[i];
			int xm = x + xv[i];
			
			if (!visited[ym][xm] && map[ym][xm] == '.') {
				visited[ym][xm] = true;
				q.push(ym * m + xm);
			}
			else if (map[ym][xm] == 'x' &&	islands[ym][xm] < parents) {
				parents = islands[ym][xm];
			}
		}
	}
	tree[parents].push_back(num);
}
int searchTree(int idx) {
	int depth = 0;
	for (int i = 0; i < tree[idx].size(); i++) {
		int temp = searchTree(tree[idx][i]);
		if (depth < temp) depth = temp;
	}
	ans[depth]++;
	return depth+1;
}

void init() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			visited[i][j] = 0;
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}
	int num = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && map[i][j] == 'x') {
				seq.push_back(i * m + j);
				setIslands(++num, i, j);
			}
		}
	}
	if (num == 0) {
		cout << -1 << endl;
		return 0;
	}
	tree.resize(num + 1);
	for (int i = 0; i < seq.size(); i++) {
		init();
		setTree(i + 1, seq[i] / m, seq[i] % m);
	}
	for (int i = 0; i < tree[0].size(); i++) {
		int depth = searchTree(tree[0][i]);
		if (depth > mMax) mMax = depth;
	}
	for (int i = 0; i < mMax; i++)
		cout << ans[i] << " ";

	return 0;

}
