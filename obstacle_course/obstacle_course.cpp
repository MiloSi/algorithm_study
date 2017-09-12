#pragma warning (disable: 4996)
#include <cstdio>
#include <queue>
#include <utility>
using namespace std;
char arr[100][100];
int visited[100][100];
const int INF = 100000;
typedef struct _NODE {
	int w;
	int loc;
	int dir;
}Node;
enum {
	NO, ES, SO, WE
};

struct myGreater {
	bool operator()(Node a, Node b) {
		return a.w > b.w;
	}
};
int yd[4] = { -1,0,1,0 };
int xd[4] = { 0,1,0,-1 };
priority_queue<Node, vector<Node>, myGreater> pq;
int n;
void dijkstra(int loc) {
	visited[loc / n][loc%n] = 0;
	int y = loc / n;
	int x = loc % n;
	for (int i = 0; i < 4; i++) {
		int yt = y + yd[i];
		int xt = x + xd[i];
		if (xt < 0 || xt > n - 1 || yt < 0 || yt > n - 1) continue;
		if (arr[yt][xt] != 'x') {
			Node nd = { 0, yt*n + xt, i };
			visited[yt][xt] = 0;
			if (arr[yt][xt] == 'B')
				return;
			pq.push(nd);
		}
	}
	while (pq.size()) {
		Node temp = pq.top();
		pq.pop();
		int y = temp.loc / n;
		int x = temp.loc % n;
		int w = temp.w;
		int d = temp.dir;
		for (int i = 0; i < 4; i++) {
			int yt = y + yd[i];
			int xt = x + xd[i];
			if (xt < 0 || xt > n - 1 || yt < 0 || yt > n - 1) continue;
			if (i == d) {
				if (arr[yt][xt] != 'x' && visited[yt][xt] >= w) {
					Node t = { w, yt*n + xt, i };
					visited[yt][xt] = w;
					pq.push(t);
				}
			}
			else {
				if (arr[yt][xt] != 'x' && visited[yt][xt] >= w+1) {
					Node t = { w+1, yt*n + xt, i };
					visited[yt][xt] = w+1;
					pq.push(t);
				}
			}
		}
	}
}
int main() {
	scanf("%d", &n);
	int y = 0, x = 0;
	int locY = 0, locX = 0;


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = INF;
			scanf(" %c", &arr[i][j]);
			if (arr[i][j] == 'A') {
				y = i;
				x = j;
			}
			if (arr[i][j] == 'B') {
				locY = i;
				locX = j;
			}
		}
	}
	dijkstra(y*n + x);
	printf("%d\n", visited[locY][locX]);
	return 0;
}