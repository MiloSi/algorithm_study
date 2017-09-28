#pragma warning (disable:4996)
#include <cstdio>
#include <iostream>
using namespace std;
typedef struct _NODE {
	int y, x;
}Node;

int w, h;
int yv[8] = { -1,-1,0,1,1,1,0,-1 };
int xv[8] = { 0, 1,1,1,0,-1,-1,-1 };

bool visited[50][50];
int arr[50][50];

void dfs(int y, int x) {

	int yf, xf;
	for (int i = 0; i < 8; i++) {
		yf = y + yv[i];
		xf = x + xv[i];

		if (xf < 0 || xf > w - 1 || yf < 0 || yf > h - 1) continue;	
		if (!visited[yf][xf] && arr[yf][xf] == 1) {
			visited[yf][xf] = true;
			dfs(yf, xf);
		}
	}
}


int main() {
	cin >> w >> h;

	while (w != 0 && h != 0) {
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++) {
				visited[i][j] = false;
				cin >> arr[i][j];
			}
		int ans = 0;
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
			{
				if (!visited[i][j] && arr[i][j]) {
					ans++;
					visited[i][j];
					dfs(i, j);
				}
			}
		cout << ans << endl;
		cin >> w >> h;
	}
	return 0;
}