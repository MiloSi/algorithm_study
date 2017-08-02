#include <iostream>
#include <array>
#include <queue>
#include <utility>
using namespace std;
typedef array<array<char, 51>, 50> Array;
Array arr;
int n, m, result = -1;
#define LOP(i,j,k) for(int i = j; i < k; i++)
const char WATER = '*';
const char DEST = 'D';
const char START = 'S';
const char WAY = '.';
const char ROCK = 'X';
const char MOVED = '@';

int yM[4] = { 0,0,-1,1 };
int xM[4] = { -1,1,0,0 };


bool isBoundary(int y, int x) {
	if (y <= n - 1 && y >= 0 && x <= m - 1 && x >= 0) {
		return true;
	}
	return false;
}
bool isDestination(int y, int x, int type, queue<pair<pair<int,int>,int>> &q) {
	pair<int, int> p = { y,x };
	if (type == 0) {
		if (arr[y][x] == WAY) {
			arr[y][x] = MOVED;
			q.push(pair<pair<int, int>, int>(p, type));
		}
		else if(arr[y][x] == DEST) {
			return true;
		}
	}
	else {
		if (arr[y][x] == WAY || arr[y][x] == MOVED) {
			arr[y][x] = WATER;
			q.push(pair<pair<int, int>, int>(p, type));
		}
	}
	return false;
}
void bfs(pair<int,int> hedg, vector<pair<int, int>> v) {
	queue<pair<pair<int, int>, int>> q;
	int q_size;
	int w = 0;
	int y, x, type;

	for (int i = 0; i < v.size(); i++) {
		q.push(pair<pair<int, int>, int>(v[i], 1));
	}
	q.push(pair<pair<int, int>, int>(hedg, 0));
	while (q.size()) {
		q_size = q.size();
		while (q_size--) {
			pair<pair<int, int>, int> p = q.front();
			q.pop();
			LOP(i, 0, 4) {
				y = p.first.first + yM[i];
				x = p.first.second + xM[i];
				type = p.second;
				if (isBoundary(y, x)) {
					if (isDestination(y, x, type, q)) {
						result = w + 1;
						return;
					}
				}	
			}
		}
		w++;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	vector<pair<int, int>> waters;
	pair<int, int> hedgehog;
	
	LOP(i, 0, n) {
		LOP(j, 0, m) {
			cin >> arr[i][j];
			switch (arr[i][j])
			{
			case WATER :
				waters.push_back(pair<int, int>(i, j));
				break;
			case START:
				hedgehog.first = i;
				hedgehog.second = j;
				arr[i][j] = MOVED;
			default:
				break;
			}
		}
	}
	bfs(hedgehog, waters);
	if (result == -1)
		cout << "KAKTUS" << endl;
	else 
		cout << result << endl;

	return 0;
}