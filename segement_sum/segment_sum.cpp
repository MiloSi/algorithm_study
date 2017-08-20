#include <iostream>
#include <vector>
#include <cmath>
#define V vector<long long>
using namespace std;
int n, m, k;

long long init(V& tree, const V& v, int index, int from, int to) {
	if (from == to) {
		return tree[index] = v[from];
	}
	return tree[index] = 
		init(tree, v, index * 2, from, (from + to) / 2) 
		+ init(tree, v, index * 2 + 1, (from + to) /2 + 1, to);
}
void update(V& tree, int index, int from, int to, int who, long long diff) {
	if (who > to || who < from) return;
	tree[index] += diff;
	if (from != to) {
		update(tree, index * 2, from, (from + to) / 2, who, diff);
		update(tree, index * 2 + 1, (from + to) / 2 + 1, to, who, diff);
	}
}
long long print(V& tree, int index, int from, int to, int left, int right) {
	if (left > to || right < from) return 0;
	if (left <= from && to <= right) return  tree[index];
	return print(tree, index * 2, from, (from + to) / 2, left, right) + print(tree, index * 2 + 1, (from + to) / 2 + 1, to, left, right);
}
int main() {
	cin >> n >> m >> k;
	int order, x, y;
	V v(n);
	for (auto &i : v) {
		cin >> i;
	}
	int h = ceil(log2(n));
	V tree((1 << h + 1));
	init(tree, v, 1, 0, n - 1);
	int diff;
	for (int i = 0; i < m + k; i++) {
		cin >> order >> x >> y;
		switch (order)
		{
		case 1: 
			diff = y - v[x - 1];
			v[x - 1] = y;
			update(tree, 1, 0, n - 1, x - 1, diff);
			break;
		case 2:
			cout << print(tree, 1, 0, n - 1, x - 1, y - 1) << endl;
			break;
		}
	}
}