#pragma warning (disable:4996) 
#include <iostream>
#include <queue>
#include <set>
using namespace std;

int testcase, n, k, m, y, x, nums, dir;
int ans;
int yv[4] = { -1, 1, 0,0 };
int xv[4] = { 0,0,-1,1 };
typedef struct _Board {
	int nums, dir;
}Board;
typedef struct _Node {
	int y, x, nums, seq;
}Node;
Board arr[100][100];
Board moved[100][100];
struct myRule {
	bool operator()(Node a, Node b) {
		if (a.seq == b.seq) {
			return a.nums < b.nums;
		}
		return a.seq > b.seq;
	}
};
priority_queue<Node, vector<Node>, myRule> pq;
void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j].dir = moved[i][j].dir;
			arr[i][j].nums = moved[i][j].nums;
			moved[i][j] = { 0, 0 };
		}
	}
}
void bfs() {
	int w = 0;
	while (pq.size()) {
		int q_size = pq.size();
		set<int> sets;
		while (q_size--) {
			Node nd = pq.top();
			pq.pop();
			int y = nd.y + yv[arr[nd.y][nd.x].dir];
			int x = nd.x + xv[arr[nd.y][nd.x].dir];

			if (sets.find(y*(n)+x) != sets.end()) {
				if (moved[y][x].nums < arr[nd.y][nd.x].nums) moved[y][x].dir = arr[nd.y][nd.x].dir;
				moved[y][x].nums += arr[nd.y][nd.x].nums;
			}
			else {
				if (y == 0 || y == n - 1 || x == 0 || x == n - 1) {
					int added = 1;
					if (arr[nd.y][nd.x].dir % 2 == 1) added = -1;
					moved[y][x].dir = arr[nd.y][nd.x].dir + added;
					moved[y][x].nums = arr[nd.y][nd.x].nums / 2;
				}
				else {
					moved[y][x].dir = arr[nd.y][nd.x].dir;
					moved[y][x].nums = arr[nd.y][nd.x].nums;
				}
				sets.insert(y*(n)+x);
				//Node nd2 = { y, x, moved[y][x].nums, w+1 };
				//pq.push(nd2);
			}
		}
		w++;

		set<int>::iterator its;

		for (its = sets.begin(); its != sets.end(); its++) {
			int y = (*its) / (n);
			int x = (*its) % (n);
			Node nd2 = { y,x, moved[y][x].nums, w };
			pq.push(nd2);
		}
		sets.clear();
		init();
		if (w == m)
			break;
	}
	while (pq.size()) {
		ans += arr[pq.top().y][pq.top().x].nums;
		pq.pop();
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	cin >> testcase;
	for (int tc = 1; tc <= testcase; tc++) {
		cin >> n >> m >> k;
		ans = 0;
		for (int i = 0; i < k; i++) {
			cin >> y >> x >> nums >> dir;
			arr[y][x] = { nums, dir - 1 };
			Node nd = { y, x, nums, 0 };
			pq.push(nd);
		}
		bfs();
		cout << "#" << tc << " " << ans << endl;

	}
	return 0;
}