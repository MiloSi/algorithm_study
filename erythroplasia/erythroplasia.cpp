#include <iostream>
#include <array>
#include <queue>

typedef struct _Node {
	int y;
	int x;
}node;

using namespace std;
#define BLUE 'B'
#define RED 'R'
#define GREEN 'G'

enum {
	NORMAL, ERYTH
};

array<array<char, 101>, 100> arr;
array<array<bool, 100>, 100> visited;
int n;
int result;
void checked(int y, int x, int isEry, char type, queue<node> &q) {

	if (!visited[y][x]) {
		if (arr[y][x] == type) {
			visited[y][x] = true;
			node nd = { y, x };
			q.push(nd);
			return;
		}
		else if (isEry == ERYTH) {
			if ((arr[y][x] == RED || arr[y][x] == GREEN) && (type == RED || type == GREEN)) {
				visited[y][x] = true;
				node nd = { y, x };
				q.push(nd);
				return;
			}
		}
	}
}


void bfs(int y, int x, int isEry) {
	queue<node> q;	
	node nd = { y,x };
	visited[y][x] = true;
	q.push(nd);

	while (q.size()) {
		nd = q.front();
		q.pop();

		y = nd.y;
		x = nd.x;
		
		if (y > 0) checked(y - 1, x, isEry, arr[y][x] ,q);
		if (y < n) checked(y +1, x, isEry, arr[y][x],q);
		if (x > 0) checked(y , x-1, isEry, arr[y][x],q);
		if (x < n) checked(y , x+1, isEry, arr[y][x],q);
	}
}

void init() {
	for (int i = 0; i < n; i++)
		visited[i].fill(false);
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	cin >> n;
	for (int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
			cin >> arr[i][j];
	}
	for (int isEry = 0; isEry <= 1; isEry++) {
		result = 0;
		init();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j]) {
					bfs(i, j, isEry);
					result++;
				}
			}
		}
		cout << result << " ";
	}
	cout << endl;

	return 0;
}
