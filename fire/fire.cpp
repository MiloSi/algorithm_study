#pragma warning (disable : 4996)
#include <iostream>
#include <queue>


const char USER = '@';
const char FIRE = '*';
const char WAY = '.';

using namespace std;
char map[1000][1001];
int result;

int n, m;

typedef struct _Node {
	int y;
	int x;
	char s;
	int weight;
}node;

void move(int y, int x, char s, int w, queue<node> &q) {
	if (s == USER)
	{
		if (map[y][x] == WAY) {
			map[y][x] = s;
			node nd = { y, x, s, w + 1 };
			q.push(nd);
		}
	}
	else {
		if (map[y][x] == WAY || map[y][x] == USER) {
			map[y][x] = s;
			node nd = { y, x, s, w + 1 };
			q.push(nd);
		}
	}
	

}

void bfs(queue<node> q) {

	while (q.size()) {
		node p = q.front();
		q.pop();

		int y = p.y;
		int x = p.x;
		int w = p.weight;
		char s = p.s;

		if (s == USER && (y == 0 || x == 0 || x == n - 1 || y == m - 1))
		{
			result = w + 1;
			return;
		}

		if (y > 0) move(y-1, x, s, w, q);
		if (y < m-1) move(y+1, x, s, w, q);
		if (x > 0) move(y, x-1, s, w, q);
		if (x < n-1) move(y, x+1, s, w, q);
	}
}

int main() {
	int t;
	node user;
	node fire;

	cin >> t;

	while (t--) {
		cin >> n >> m;

		queue<node> q;
		result = 0;

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];


				switch (map[i][j])
				{
				case FIRE:
					fire = { i, j, FIRE, 0 };
					q.push(fire);
					break;
				case USER:
					user = { i, j, USER, 0 };
					break;
				}
			}
		}
		q.push(user);

		bfs(q);
		if (result == 0)
			cout << "IMPOSSIBLE" << endl;

		else
			cout << result << endl;

		fflush(stdin);

	}
	return 0;
}