#include <iostream>
using namespace std;
typedef struct _NODE {
	int y, x;
}Node;

inline int _MAX(int a, int b) {
	return  a > b ? a: b;
}
#define LOP(i,j) for(int i = 0; i < j; i++)
int arr[8][8];
int n, k;
int yv[4] = { -1,0,1,0 };
int xv[4] = { 0,1,0,-1 };
int ans = 0;
Node v[30];
bool isOkay(int y, int x) {
	if (y < 0 || y > n - 1 || x < 0 || x > n - 1) return false;
	return true;
}

void dfs(int y, int x, int w, bool isDig, int v_size) {
	LOP(i, 4) {
		int yf = y + yv[i];
		int xf = x + xv[i];
		bool already = false;
		if (isOkay(yf, xf)) {
			LOP(j, v_size) {
				if (yf == v[j].y && xf == v[j].x) {
					already = true;
					break;
				}
			}
			if (!already) {
				if (arr[yf][xf] < w) {
					v[v_size] = { yf,xf };
					dfs(yf, xf, arr[yf][xf], isDig, v_size+1);
				}
				else if (arr[yf][xf] >= w && !isDig) {
					if (arr[yf][xf] - k < w) {
						Node nd = { yf,xf };
						v[v_size] = nd;
						dfs(yf, xf, arr[y][x]-1, true, v_size + 1);
					}
				}
			}
		}
	}
	if (ans < v_size)	{
		ans = v_size;
	}
}
int main() {

	int t;
	int top;
	cin >> t;
	LOP(test, t) {
		cin >> n >> k;
		ans = 0;
		top = 0;
		LOP(i, n) {
			LOP(j, n) {
				cin >> arr[i][j];
				if (arr[i][j] > top) top = arr[i][j];
			}
		}
		LOP(i, n) {
			LOP(j, n) {
				if (arr[i][j] == top) {
					v[0] = { i,j };
					dfs(i, j, top, false, 1);
				}
			}
		}
		cout << "#" << test+1 << " " <<ans << endl;
	}
	return 0;
}