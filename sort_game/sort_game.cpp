#pragma warning (disable:4996)
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
bool visited[2 << 24];
int n, k;
int arr[8], _data[8];
bool isOkay(int *arrs) {
	for (int i = 0; i < n - 1; i++)
		if (arrs[i] > arrs[i + 1]) return false;
	return true;
}
void _sort(int c) {
	for (int i = 0; i < n; i++)
		_data[i] = arr[i];
	reverse(_data + c, _data + c + k);

}
int bfs() {
	int w = 0;
	int d = 0, d1;
	if (isOkay(arr)) return 0;
	for (int i = 0; i < n; i++) {
		d += (1 << (i * 3)) * (arr[i] - 1);
	}
	visited[d] = true;
	queue<int> q;
	q.push(d);
	while (q.size()) {
		int q_size = q.size();
		while (q_size) {
			d = q.front();
			q.pop();
			for (int i = 0; i < n; i++) {
				arr[i] = (d % 8) + 1;
				d = d >> 3;
			}
			for (int i = 0; i < n; i++) {
				if (i + k > n) break;
				_sort(i);
				if (isOkay(_data)) return w + 1;
				d1 = 0;
				for (int i = 0; i < n; i++) {
					d1 += (1 << (i * 3)) * (_data[i] - 1);
				}
				if (!visited[d1]) {
					visited[d1] = true;
					q.push(d1);
				}
			}
			q_size--;
		}
		w++;
	}
	return w;
}
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	printf("%d\n", bfs());
	return 0;
}