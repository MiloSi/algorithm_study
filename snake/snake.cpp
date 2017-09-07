#pragma warning (disable : 4996)
#include <cstdio>
#include <utility>
#include <vector>
#include <cmath>
using namespace std;
#define PIC pair<int,char>
#define PI pair<int,int>
int l, n;
vector<PIC> v;
PI coord[1001];
int idx = 0;
int dy[4] = { 1,0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int dir = 1;
int INF = 200000002;
PI setting(int a, int b) {
	PI p;
	if (a < b)
		p = { a, b };
	else
		p = { b, a };
	return p;
}
long long int sol() {
	int y = 0, x = 0;
	long long int len = 0;
	for (int i = 0; i < n; i++) {
		int x1 = x + v[i].first * dx[dir];
		int y1 = y + v[i].first * dy[dir];
		for (int j = 0; j < idx - 1; j++) {
			PI py = setting(coord[j].first, coord[j + 1].first);
			PI px = setting(coord[j].second, coord[j + 1].second);
			if (dir == 0) { // x == same y++
				if (px.first <= x1 && x1 <= px.second && y1 >= py.first && py.first > y) {
					return len += py.first - y;
				}
			}
			else if (dir == 1) {
				if (py.first <= y1 && y1 <= py.second && x1 >= px.first && px.first > x) {
					return len += px.first - x;
				}
			}
			else if (dir == 2) {
				if (px.first <= x1 && x1 <= px.second && py.second >= y1 && y > py.second) {
					return len += y - py.first;
				}
			}
			else {
				if (py.first <= y1 && y1 <= py.second && px.second >= x1 && x > px.second) {
					return	len += x - px.first;
				}
			}
		}
		if (abs(x1) > l || abs(y1) > l) {
			if (dir == 0)
				len += l - y + 1;
			else if (dir == 1)
				len += l - x + 1;
			else if (dir == 2)
				len += abs(-l - y) + 1;
			else
				len += abs(-l - x) + 1;
			return len;
		}
		len += abs(x1 - x) + abs(y1 - y);
		y = y1;
		x = x1;
		coord[++idx] = { y1, x1 };

		if (v[i].second == 'R')	dir = (dir + 1) % 4;
		else 	dir = (dir + 3) % 4;
	}
	int x1 = x + INF* dx[dir];
	int y1 = y + INF* dy[dir];
	for (int j = 0; j < idx - 1; j++) {
		PI py = setting(coord[j].first, coord[j + 1].first);
		PI px = setting(coord[j].second, coord[j + 1].second);
		if (dir == 0) { // x == same y++
			if (px.first <= x1 && x1 <= px.second && y1 >= py.first && py.first > y) {
				return len += py.first - y;
			}
		}
		else if (dir == 1) {
			if (py.first <= y1 && y1 <= py.second && x1 >= px.first && px.first > x) {
				return len += px.first - x;
			}
		}
		else if (dir == 2) {
			if (px.first <= x1 && x1 <= px.second && py.second >= y1 && y > py.second) {
				return len += y - py.first;
			}
		}
		else {
			if (py.first <= y1 && y1 <= py.second && px.second >= x1 && x > px.second) {
				return	len += x - px.first;
			}
		}
	}

	if (dir == 0)
		len += l - y + 1;
	else if (dir == 1)
		len += l - x + 1;
	else if (dir == 2)
		len += abs(-l - y) + 1;
	else
		len += abs(-l - x) + 1;
	return len;
}
int main() {
	scanf("%d%d", &l, &n);
	v.resize(n);
	for (int i = 0; i < n; i++) {
		PIC p;
		scanf("%d %c", &p.first, &p.second);
		v[i] = p;
	}
	printf("%lld\n", sol());
	return 0;
}

