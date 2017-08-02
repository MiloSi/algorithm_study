#include <iostream>
#include <array>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
typedef array<array<char, 51>, 50> Array;
typedef array<array<array<bool, 50>, 50>, 2> Visited;

const char BEGIN = 'B';
const char DEST = 'E';
const char WAY = '0';


enum {
	VERTICAL,
	HORIZONTAL
};


typedef struct _NODE {
	int y;
	int x;
	int state;
	int w;
}node;
Array arr;
Visited visited;
int n;
int result = 0;
#define LOP(i,j,k) for(int i = 0; i < k; i++)


void moved(int y, int x, int state, int w, queue<node> &q) {
	bool isOkay = false;

	
	if (state == VERTICAL && !visited[VERTICAL][y][x]) {
		if (arr[y - 1][x] == WAY &&  arr[y][x] == WAY && arr[y + 1][x] == WAY) 
			isOkay = true;
		
	}
	else if(state == HORIZONTAL && !visited[HORIZONTAL][y][x]){
		if (arr[y][x - 1] == WAY &&  arr[y][x] == WAY && arr[y][x + 1] == WAY) 
			isOkay = true;
	}

	if (isOkay) {
		node nd = { y,x,state, w + 1 };
		visited[state][y][x] = true;
		q.push(nd);
	}

}
void rotated(int y, int x, int state, int w, queue<node> &q) {
	if (!visited[(state + 1) % 2][y][x]) {
		bool isOkay = true;

		for(int i = y-1; i <= y+1; i++)
			for (int j = x - 1; j <= x + 1; j++) {
				if (arr[i][j] != WAY) {
					isOkay = false;
					break;
				}
			}
		if (isOkay) {
			visited[(state + 1) % 2][y][x] = true;
			node nd = { y, x, (state + 1) % 2 , w + 1 };
			q.push(nd);
		}
	}
}

void bfs(node start, node end) {	
	queue<node> q;
	visited[start.state][start.y][start.x] = true;
	q.push(start);
	node nd;
	int y;
	int x;
	int w;
	int state;

	while (q.size()) {
		nd = q.front();
		q.pop();

		y = nd.y;
		x = nd.x;
		w = nd.w;
		state = nd.state;


		if (y == end.y && x == end.x && state == state) {
			result = w;
			return;
		}
		if (state == VERTICAL) {
			int k = 0;
			if (x > 0) {
				moved(y, x-1, state, w, q); k++;
			}
			if (x < n-1) {
				moved(y, x+1, state, w, q); k++;
			}
			if (y > 1) {
				moved(y-1, x, state, w, q);
			}
			if (y < n-2) {
				moved(y+1, x, state, w, q);
			}
			if (k == 2) {
				rotated(y, x, state, w, q);
			}

		}
		else {
			int k = 0;
			if (x > 1) {
				moved(y, x - 1, state, w, q);
			}
			if (x < n - 2) {
				moved(y, x + 1, state, w, q); 
			}
			if (y > 0) {
				moved(y - 1, x, state, w, q); k++;
			}
			if (y < n - 1) {
				moved(y + 1, x, state, w, q); k++;
			}
			if (k == 2) {
				rotated(y, x, state, w, q);
			}
		}
	}
}

void setting(node& nd, vector<pair<int, int>> ve) {
	nd.y = ve[1].first;
	nd.x = ve[1].second;
	nd.w = 0;
	if (ve[1].first == ve[0].first) // ¼¼·Î
		nd.state = HORIZONTAL;
	else
		nd.state = VERTICAL;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;

	node start;
	node end;


	vector<pair<int,int>> b; //start
	vector<pair<int,int>> d; //end

	LOP(i, 0, n) LOP(j, 0, n) {
		cin >> arr[i][j];

		if (arr[i][j] == BEGIN) {
			pair<int, int> p = { i,j };
			b.push_back(p);
			arr[i][j] = WAY;
		}
		else if (arr[i][j] == DEST) {
			pair<int, int> p = { i,j };
			d.push_back(p);
			arr[i][j] = WAY;
		}
	}
	setting(start, b);
	setting(end, d);

	bfs(start, end);

	cout << result << endl;
	return 0;
}