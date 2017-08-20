#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
#define V vector<int>
#define VP vector<pair<int, int>>
inline int MAX(int a, int b) {
	return a > b ? a : b;
}
bool rull(pair<int, int> a, pair<int, int>b) {
	if (a.first == b.first) {
		return a.second > b.second;
	}
	else {
		return a.first < b.first;
	}
}



int n;
void update(V& tree, int index, int from, int to, int who, int value) {
	if (who < from || who > to) return; 
	tree[index] = MAX(tree[index], value);
	if (from != to) {
		update(tree, index * 2, from, (from + to) / 2, who, value);
		update(tree, index * 2 + 1, (from + to) / 2 + 1, to, who, value);
	}
}
int search(V& tree, int index, int from, int to, int left, int right) {
	if (left > to || right < from) return 0;
	if (from >= left && to <= right) return tree[index];
	return MAX(search(tree, index * 2, from, (from + to) / 2, left, right), search(tree, index * 2 + 1, (from + to) / 2 + 1, to, left, right));
}
int main() {
	int h;
	cin >> n;
	VP arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first;
		arr[i].second = i;
	}
	sort(arr.begin(), arr.end(), rull);
	h = ceil(log2(n));
	V tree(1 << (h + 1), 0);
	for (int i = 0; i < n; i++) {
		int v = search(tree, 1, 0, n - 1, 0, arr[i].second);
		update(tree, 1, 0, n - 1, arr[i].second, v+1);
	}
	cout << tree[1] << endl;
	return 0;
}