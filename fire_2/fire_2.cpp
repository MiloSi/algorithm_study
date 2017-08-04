#include <iostream>
#include <array>
#include <utility>
#include <queue>
#include <vector>
using namespace std;
array<array<char, 1000>, 1000> arr;
const char USER = 'J';
const char FIRE = 'F';
const char SPACE = '.';
const char WALL = '#';
const char MOVED = '@';
int r, c, result = -1;
#define LOP(i,j,k) for(int i = j; i < k; i++)
#define INPUT pair<pair<int,int>,char>
const int xf[4] = { 0,0,-1,1 };
const int yf[4] = { -1,1,0,0 };
bool isBoundary(int y, int x) {
	if (y == 0 || y == r - 1 || x == 0 || x == c - 1) {
		return true;
	}
	return false;
}
void moving(int y1, int x1, char type, queue<pair<pair<int, int>, char>>& q) {
	int y, x;
	if (type == USER) {
		LOP(i, 0, 4) {
			y = y1 + yf[i];
			x = x1 + xf[i];
			if (arr[y][x] == SPACE) {
				arr[y][x] = MOVED;
				q.push(INPUT(pair<int, int>(y, x), type));
			}
		}
	}
	else if(type == FIRE) {
		LOP(i, 0, 4) {
			y = y1 + yf[i];
			x = x1 + xf[i];
			if (y == 0 || y == r - 1 || x == 0 || x == c - 1) continue;
			if (arr[y][x] == SPACE || arr[y][x] == MOVED) {
				arr[y][x] = FIRE;
				q.push(INPUT(pair<int, int>(y, x), type));
			}
		}
	}

}
void bfs(pair<int,int> user, vector<pair<int,int>> fires) {
	queue<pair<pair<int, int>, char>> q;
	int y, x, w;
	bool isUser = false;
	LOP(i, 0, fires.size()) {
		q.push(INPUT(fires[i], FIRE));
	}
	q.push(INPUT(user, USER));
	w = 0;
	while (q.size())
	{
		int q_size = q.size();
		isUser = false;
		while (q_size--) {
			pair<int, int> p = q.front().first;
			char type = q.front().second;
			q.pop();
			if (type == USER) {
				isUser = true;
				if (isBoundary(p.first, p.second)) {
					result = w + 1;
					return;
				}
			}
			moving(p.first, p.second, type, q);
		}
		if (!isUser) return;
		w++;
	}
}
int main() {
	cin >> r >> c;
	vector<pair<int, int>> fires;
	pair<int, int> user;
	LOP(i, 0, r) {
		LOP(j, 0, c) {
			cin >> arr[i][j];
			switch (arr[i][j])
			{
			case USER:
				user = { i, j };
				arr[i][j] = MOVED;
				break;
			case FIRE:
				fires.push_back(pair<int, int>(i, j));
				break;
			default:
				break;
			}
		}
	}
	bfs(user, fires);
	if (result == -1)
		cout << "IMPOSSIBLE" << endl;
	else 
		cout << result << endl;

	return 0;
}