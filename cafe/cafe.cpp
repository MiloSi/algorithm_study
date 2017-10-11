#pragma warning (disable:4996)
#include <iostream>
#include <set>
using namespace std;
int arr[20][20];
int t, n, ans;

void leftDown(int y, int x, int h, int w, set<int> s);
void leftUp(int y, int x, int h, int w, set<int> s);
void rightUp(int y, int x, int h, int w, set<int> s);

void rightDown(int y, int x, int h, int w, set<int> s) {

	if (s.find(arr[y][x]) != s.end()) return;
	s.insert(arr[y][x]);
	
	if (y < n && x < n) {
		rightDown(y + 1, x + 1, h + 1, w, s);
		if (h >= 1 && y < n-1)
			leftDown(y + 1, x - 1, h, w + 1, s);
	}
}
void leftDown(int y, int x, int h, int w, set<int> s) {
	if (s.find(arr[y][x]) != s.end()) return;
		s.insert(arr[y][x]);
	if (y < n && x > 0) {
		if(x >= 1)
			leftDown(y + 1, x - 1, h, w + 1, s);
		if( (x - h) >= 0 && w >= 1)
			leftUp(y - 1, x - 1, h-1 , w, s);
	}
}
void leftUp(int y, int x, int h, int w, set<int> s) {
	if (s.find(arr[y][x]) != s.end()) return;
		s.insert(arr[y][x]);

	if(h > 0) leftUp(y - 1, x - 1, h - 1, w, s);
	else rightUp(y - 1, x + 1, h, w - 1, s);

}
void rightUp(int y, int x, int h, int w, set<int> s) {
	if (h == 0 && w == 0)	{
		int s_size = s.size();
		if (ans < s_size) {
			ans = s_size;
		}
		return;
	}
	if (s.find(arr[y][x]) != s.end()) return;
	
	s.insert(arr[y][x]);
	rightUp(y - 1, x + 1, h, w - 1, s);
}


int main() {
	set<int> s;
	freopen("input.txt", "r", stdin);
	cin >> t;

	for (int i = 1; i <= t; i++) {
		ans = -1;
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}
		for (int i = 0; i < n - 1; i++) {
			for (int j = 1; j < n - 1; j++) {
				rightDown(i, j, 0, 0, s);
			}
		}
		cout << "#" << i << " " << ans << endl;
	}


	return 0;
}