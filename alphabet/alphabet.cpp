#include <iostream>
typedef struct _Node {
	int w = 0;
	bool visited[26] = { false, };
}Node;
using namespace std;
char board[20][21];
bool visited[26];
int result = 0;
int r, c;
int yf[4] = { -1,1,0,0 };
int xf[4] = { 0,0,-1,1 };
bool isOkay(int y, int x) {
	if (y >= 0 && y < r && x >= 0 && x < c) return true;
	return false;
}
void dfs(int y, int x, Node nd) {
	nd.w++;
	nd.visited[(board[y][x] - 65)] = true;
	int x1, y1;
	for (int i = 0; i < 4; i++) {
		x1 = x + xf[i];
		y1 = y + yf[i];
		if (isOkay(y1, x1)) {
			if (!nd.visited[board[y1][x1] - 65]) {
				dfs(y1, x1, nd);
			}
		}
	}
	if (result < nd.w) result = nd.w;
}
int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++)
		cin >> board[i];
	Node nd;
	dfs(0, 0, nd);
	cout << result << endl;
	return 0;
}

