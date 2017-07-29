#include <iostream>
#include <queue>
#include <array>
using namespace std;
int n, m;


const char WATER = 'W';
const char LAND = 'L';

inline int MAX(int a, int b) {
	return a > b ? a : b;
}

typedef struct _NODE {
	int y;
	int x;
	int w;
}node;


#define LOP(i,j,k) for(int i =j; i< k; i++)
typedef array<array< char, 51>, 50> arr;
typedef array<array< char, 51>, 50> isVisited;

isVisited visited = { false, };
arr islands;

int result = 0;

void checked(int y, int x, int w, queue<node> &q)
{
	if (!visited[y][x] && islands[y][x] == LAND) {
		visited[y][x] = true;
		node nd = { y,x,w + 1 };
		q.push(nd);
	}
}

void bfs(int y, int x) {
	int w;
	queue<node> q;
	node nd = { y, x, 0 };
	LOP(i, 0, n) LOP(j, 0, m) visited[i][j] = false;
	visited[y][x] = true;
	q.push(nd);
	while (q.size()) {
		nd = q.front();
		q.pop();
		y = nd.y;
		x = nd.x;
		w = nd.w;

		if (y > 0) checked(y-1, x, w, q);
		if (y < n-1) checked(y+1, x, w, q);
		if (x > 0) checked(y, x-1, w, q);
		if (x < m-1) checked(y, x+1, w, q);
	}
	result = MAX(result, w);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(false);
	cin >> n >> m;

	LOP(i, 0, n) LOP(j, 0, m) cin >> islands[i][j];
	LOP(i, 0, n) LOP(j, 0, m) if (islands[i][j] == LAND) bfs(i, j);

	cout << result << endl;

	return 0;
}