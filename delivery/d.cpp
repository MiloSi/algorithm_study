#pragma warning (disable:4996)
#include <cstdio>
#include <vector>
#include <queue>	
#include <memory.h>
using namespace std;

typedef struct Node {
	int y,  x;
	int dir;
	int c;
}node;
int xv[4] = { 0,1,0,-1 };
int yv[4] = { -1,0,1,0 };
int n, m, ans;
char arr[50][50];
bool visited[50][50][4];

bool isOkay(int y, int x) {
	if (y < 0 || y >n - 1 || x <0 || x> m - 1) 
		return false;
	return true;
}
int bfs(node start, vector<node> dest) {
	queue<node> q1, q2;
	int y, x, w = 1, okay = -1;
	node new_nd; 
	q1.push(start);
	while (q1.size()) {
		int q_size = q1.size();
		while (q_size--) {
			node nd = q1.front();
			q1.pop();
			for (int i = 0; i < 4; i++) {
				if (nd.dir == i) continue;
				y = nd.y + yv[i];
				x = nd.x + xv[i];
				if (isOkay(y, x)) {
					if (arr[y][x] != '#' && !visited[y][x][i]) {
						if (arr[y][x] == 'C') {
							for (int k = 0; k < 2; k++) {
								if (dest[k].y == y && dest[k].x == x) {
									if (okay == -1 || okay == k) {
										okay = k;
										new_nd = { y,x, i };
										q2.push(new_nd);
									}
								}
							}
						}
						else {
							visited[y][x][i] = true;
							new_nd = { y,x,i };
							q1.push(new_nd);
						}
					}
				}
			}
		}
		w++;
		if (okay != -1) break;
	}
	if (okay == -1) return -1;
	arr[dest[okay].y][dest[okay].x] = '.';
	memset(visited, 0, sizeof(visited));

	while (q2.size()) {
		int q_size = q2.size();
		while (q_size--) {
			node nd = q2.front();
			q2.pop();
			for (int i = 0; i < 4; i++) {
				if (nd.dir == i) continue;
				y = nd.y + yv[i];
				x = nd.x + xv[i];
				if (isOkay(y, x)) {
					if (arr[y][x] != '#' && !visited[y][x][i]) {
						if (arr[y][x] == 'C') {
							return  w;
						}
						else {
							visited[y][x][i] = true;
							new_nd = { y,x,i };
							q2.push(new_nd);
						}

					}
				}
			}
		}
		w++;
	}
	return -1;
}

int main() {
	Node start;
	vector<Node> dest;
	scanf("%d%d", &n, &m);

	for(int i = 0; i < n; i++){
		for (int j = 0; j < m; j++) {
			scanf(" %c", &arr[i][j]);
			if (arr[i][j] == 'S') {
				start = { i , j , -1};
			}
			else if (arr[i][j] == 'C') {
				node nd = { i, j };
				dest.push_back(nd);
			}
		}
	}
	printf("%d\n", bfs(start, dest));

}
