#include <iostream>
#include <queue>
#include <memory.h>

typedef struct _Node {
	int y;
	int x;
}node;
using namespace std;

int zone[101][101];
bool visited[101][101];
int n;
int mHeight = 0;
int mLow = 101;
int _Max = 0;
int result= 0;


void checked(int y, int x, int h, queue<node> &q) {

	if (!visited[y][x] && zone[y][x] > h) {
		node nd = { y, x };
		q.push(nd);
		visited[y][x] = true;
	}

}
void bfs(int y, int x, int h) {
	queue<node> q;
	node nd = { y, x };
	visited[y][x] = true;
	q.push(nd);

	while (q.size()) {
		nd = q.front();
		q.pop();

		y = nd.y;
		x = nd.x;
		if (x > 1) checked(y, x-1, h, q);
		if (x < n) checked(y, x+1, h, q);
		if (y > 1) checked(y-1, x, h, q);
		if (y < n) checked(y+1, x, h, q);
	}
}
int main() {
	cin >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> zone[i][j];
			if(mHeight < zone[i][j])
				mHeight = zone[i][j];
			if (mLow > zone[i][j])
				mLow = zone[i][j];
		}

	for (int h = mLow-1; h < mHeight; h++) {
		memset(visited, false, sizeof(visited));
		_Max = 0;
		for (int i = 1; i <= n; i++)	{
			for (int j = 1; j <= n; j++) {
				if (!visited[i][j] && zone[i][j] > h) {
					_Max++;
					bfs(i,j,h);
				}
			}
		}
		if (_Max > result)
			result = _Max;
	}

	cout << result << endl;

	return 0;
}

