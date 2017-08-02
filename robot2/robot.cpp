#include <iostream>
#include <array>
#include <queue>
using namespace std;

enum {
	EAST = 1,WEST,SOUTH,NORTH 
};


typedef struct _Node {
	int y;
	int x;
	int w;
	int state;
}node;
typedef array<array<int, 101>, 101> Array;
typedef array<array<array<bool, 101>, 101>, 5> Visited;
Array board;
Visited visited;
int n, m;
int result = 0;
#define LOP(i, j, k) for(int i = j; i <= k; i++)
#define LOOP(i, j, k) for(int i = j; i >= k; i--)


void moved(int y, int x, int w, int state, queue<node> &q) {
	if (state == SOUTH) LOP(i, y + 1, y + 3) {
		if (i > n) return;
		if (visited[state][i][x]) return;
		if (board[i][x] != 0) break;
		visited[state][i][x] = true;
		node nd = { i, x, w + 1, state };
		q.push(nd);
	}
	else if (state == NORTH) LOOP(i, y - 1, y - 3) {
		if (i < 1) return;
		if (visited[state][i][x]) return;
		if (board[i][x] != 0) break;
		visited[state][i][x] = true;
		node nd = { i, x, w + 1, state };
		q.push(nd);
	}
	else if (state == EAST) LOP(i, x + 1, x + 3) {
		if (i > m) return;
		if (visited[state][y][i]) return;
		if (board[y][i] != 0) break;
		visited[state][y][i] = true;
		node nd = { y, i, w + 1, state };
		q.push(nd);
	}
	else  LOOP(i, x - 1, x - 3) {
		if (i < 1) return;
		if (visited[state][y][i]) return;
		if (board[y][i] != 0) break;
		visited[state][y][i] = true;
		node nd = { y, i, w + 1, state };
		q.push(nd);
	}

}
void rotated(int y, int x, int w, int state, queue<node> &q) {
	if (state == NORTH || state == SOUTH) {
		LOP(i, 1, 2) {
			if (!visited[i][y][x]) {
				visited[i][y][x] = true;
				node nd = { y,x, w + 1, i };
				q.push(nd);
			}
		}
	}
	else if (state == WEST || state == EAST) {
		LOP(i, 3, 4) {
			if (!visited[i][y][x]) {
				visited[i][y][x] = true;
				node nd = { y,x, w + 1, i };
				q.push(nd);
			}
		}
	}
}
bool isDest(node n1, node n2) {
	if (n1.x == n2.x && n1.y == n2.y && n1.state == n2.state) {
		result = n1.w;
		return true;
	}
	return false;
}
void bfs() {
	node start;
	node end;
	queue<node> q;
	int y, x, w, state;

	cin >> start.y >> start.x >> start.state;
	cin >> end.y >> end.x >> end.state;
	start.w = 0;
	visited[start.state][start.y][start.x] = true;
	q.push(start);


	while (q.size()) {
		node nd = q.front();
		q.pop();
		if (isDest(nd, end)) return;
		y = nd.y;
		x = nd.x;
		w = nd.w;
		state = nd.state;

		moved(y, x, w, state, q);
		rotated(y, x, w, state, q);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;

	LOP(i, 1, n) LOP(j, 1, m) {
		cin >> board[i][j];
	}
	bfs();
	cout << result << endl;
	return 0;
}