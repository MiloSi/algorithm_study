#include <iostream>
#include <queue>
using namespace std;

typedef struct _Node {
	int z;
	int y;
	int x;
	int w;
}Node;
queue<Node> q;
int w = 0;

int box[102][102][102];



void checkTomato(int x, int y, int z, int w) {
	if (box[z][y][x] == 0)
	{
		box[z][y][x] = 1;
		Node node = { z, y, x, w };
		q.push(node);
	}
}


void bfs(int m, int n, int h)
{
	int x, y, z;

	while (q.size())
	{
		Node node = q.front();
		q.pop();

		if(w < node.w)
			w = node.w;
		x = node.x;
		y = node.y;
		z = node.z;

		if (x > 1) checkTomato(x-1, y, z, w + 1);
		if (y > 1) checkTomato(x, y-1, z, w + 1);
		if (z > 1) checkTomato(x, y, z-1, w + 1);
		if (x < m) checkTomato(x+1, y, z, w + 1);
		if (y < n) checkTomato(x, y+1, z, w + 1);
		if (z < h) checkTomato(x, y, z+1, w + 1);
	}

}
int main() {

	int m, n, h; // x, y, z;

	cin >> m >> n >> h;

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= m; k++) {
				cin >> box[i][j][k];
				if (box[i][j][k] == 1) {
					Node node = { i,j,k,0 };
					q.push(node);
				}
			}
		}
	}
	bfs(m,n,h);

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= m; k++) {
				if (box[i][j][k] == 0) {
					w = -1;
					break;
				}
			}
		}
	}
	cout << w << endl;


	return 0;
}

