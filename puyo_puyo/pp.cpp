#pragma warning (disable : 4996)
#include <stdio.h>
#include <memory.h>
#include <queue>
char board[12][7];
bool visited[12][6];
int chain = 0;
int yv[4] = { -1,0,1,0 };
int xv[4] = { 0,1,0,-1 };
int emptys[6];
using namespace std;
typedef pair<int, int> PI;

void clears(int ys, int xs, char puyo) {
	queue<PI> q;
	q.push(make_pair(ys, xs));

	while (q.size()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int yf = y + yv[i];
			int xf = x + xv[i];
			if (xf == -1 || xf == 6 || yf == -1 || yf == 12) continue;
			if (board[yf][xf] == puyo) {
				board[yf][xf] = '.';
				q.push(make_pair(yf, xf));
			}
		}
	}
}
bool bfs(int ys, int xs, char puyo) {
	int nums = 1;
	bool fourth = false;
	queue<PI> q;
	q.push(make_pair(ys, xs));
	visited[ys][xs] = 1;
	
	while (q.size()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int yf = y + yv[i];
			int xf = x + xv[i];
			
			if (xf == -1 || xf == 6 || yf == -1 || yf == 12) continue;
			if (board[yf][xf] == puyo && !visited[yf][xf]) {
				visited[yf][xf] = true;
				nums++;
				if (nums == 4) 
					fourth = true;
				q.push(make_pair(yf, xf));
			}
		}
	}
	return fourth;
}


bool chaining() {
	bool isChain = false;
	for (int i = 11; i >= 0; i--) {
		for (int j = 0; j < 6; j++) {
			if (!visited[i][j] && board[i][j] != '.') {
				bool fourth = bfs(i, j, board[i][j]);
				if (fourth) {
					clears(i, j, board[i][j]);
					isChain = true;
				}
			}
		}
	}
	return isChain;
}
void gravity() {

	for (int j = 0; j < 6; j++)
		emptys[j] = 11;

	for (int i = 11; i >= 0; i--) {
		for (int j = 0; j < 6; j++) {
			if(board[i][j] != '.') {
				char temp = board[i][j];
				board[i][j] = '.';
				board[emptys[j]--][j] = temp;
			}
		}
	}
}

bool simulation() {
	bool changing = false;
	memset(visited, 0, sizeof(visited));

	// 터지는거 구현
	if (chaining()) {
		// 중력 보정
		gravity();
		return true;
	}
	return false;
}

int main() {
	for (int i = 0; i < 12; i++)
		scanf("%s", board[i]);
	while (simulation()) {
		chain++;
	}
	printf("%d\n", chain);
	return 0;
}
