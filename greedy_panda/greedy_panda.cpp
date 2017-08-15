#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define PII pair<int, int>
#define LOP(i,j) for(int i = 0; i < j; i++)
int n;
int arr[500][500];
int visited[500][500];
int result = 1;
int yf[4] = { 1,-1,0,0 };
int xf[4] = { 0,0,1,-1 };
void bfs(int y, int x) {
	int y1, x1,  w = 0;
	LOP(i, 4) {
		y1 = y + yf[i];
		x1 = x + xf[i];
		if (y1 < 0 || y1 > n - 1 || x1 < 0 || x1 > n - 1) continue;
		if (arr[y1][x1] < arr[y][x]) {
			if (visited[y1][x1] == 0) bfs(y1, x1);
			if (visited[y1][x1] > w) {
				w = visited[y1][x1];
			}
		}
	}
	visited[y][x] = w + 1;
	if (visited[y][x] > result) result = visited[y][x];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	LOP(i, n) LOP(j, n) cin >> arr[i][j];
	LOP(i, n) {
		LOP(j, n) {
			if (visited[i][j] == 0) {
				bfs(i, j); 
			}
		}
	}

	cout << result << endl;
	return 0;
}