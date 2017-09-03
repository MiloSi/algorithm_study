#pragma warning (disable:4996)
#include <cstdio>
int arr[16][16];
int visited[16][1 << 16];
int n;
 const int INF = 0x6fffffff;
int checked;
inline int _Min(int a, int b) {
	return  a < b ? a : b;
}

int travel(int c, int bitmask) {
	auto &d = visited[c][bitmask];
	if (d != 0) return d;

	if (bitmask == checked) {
		if (arr[c][0]) return arr[c][0];
		else return INF;
	}
	d = INF;
	for (int i = 0; i < n; i++) {
		if (bitmask & (1 << i) || !arr[c][i]) continue;
		d = _Min(d, travel(i, bitmask + (1 <<i)) +arr[c][i]);
	}
	return d;
}
int main() {
	scanf("%d", &n);
	checked = (1 << n) -1;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) scanf("%d", &arr[i][j]);
	printf("%d\n", travel(0, 1));
	return 0;
}