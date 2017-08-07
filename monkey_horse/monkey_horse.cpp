#include<iostream>
#include <queue>
#include <array>
using namespace std;
int k, w, h;
typedef array<array<int, 200>, 200> Array;
Array board;
bool visited[31][200][200];
#define LOP(i, j) for(int i = 0; i < j; i++)
#define PP pair<int,int>
int x_m[4] = { 0,0,-1,1 };
int y_m[4] = { -1,1,0,0 };
int x_h[8] = { -1,1,-2,2,-2,2,-1,1 };
int y_h[8] = { -2,-2,-1,-1,1,1,2,2 };
bool isOkay(int y, int x) {
	if (y < 0 || y > h - 1 || x < 0 || x > w - 1) return false;
	return true;
}
bool move(int y, int x, int s) {
	if (board[y][x] == 0) {
		if (!visited[s][y][x]) {
			visited[s][y][x] = true;
			return true;
		}
	}
	return false;
}
int bfs() {
	int y, x, weight = 1, q_size, state;
	PP location;
	queue<PP> q;
	visited[0][0][0] = 1;
	if (0 == w - 1 && 0 == h - 1) {
		return 0;
	}
	q.push(PP(0, 1));
	while (q.size()) {
		q_size = q.size();
		while (q_size--) {
			location.first = (q.front().first / w);
			location.second = (q.front().first % w);
			state = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				y = location.first + y_m[i];
				x = location.second + x_m[i];
				if (y == h - 1 && x == w - 1) return weight;
				if (isOkay(y, x)) {
					if (move(y, x, state)) {
						q.push(PP(y*w + x, state));
					}
				}
			}
			if (state <= k) {
				for (int i = 0; i < 8; i++) {
					y = location.first + y_h[i];
					x = location.second + x_h[i];
					if (y == h - 1 && x == w - 1) return weight;
					if (isOkay(y, x)) {
						if (move(y, x, state + 1)) {
							q.push(PP(y*w + x, state + 1));
						}
					}
				}
			}
		}
		weight++;
	}
	return -1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> k >> w >> h;
	LOP(i, h) {
		LOP(j, w) {
			cin >> board[i][j];
		}
	}
	cout << bfs() << endl;
	return 0;
}