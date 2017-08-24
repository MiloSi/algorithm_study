#pragma warning(disable : 4996)
#include <cstdio>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;
#define VP vector<pair<int,int>>
#define P pair<int,int>
#define LOP(i, j) for(int i = 1; i <= j; i++)
const int _INT_MAX = 1000000001;
inline P MIN_MAX(P a, P b) {
	P t;
	if (a.first == 0) t.first = b.first;
	else if (b.first == 0) t.first = a.first;
	else t.first = a.first < b.first ? a.first : b.first;
	t.second = a.second > b.second ? a.second : b.second;
	return t;
}
P init(VP& tree, const vector<int>& vec, int node, int start, int end) {
	if (start == end) {
		tree[node].first = vec[start];
		tree[node].second = vec[start];
		return tree[node];
	}
	int m = (start + end) / 2;
	return tree[node] = MIN_MAX(init(tree, vec, node * 2, start, m), init(tree, vec, node * 2 + 1, m+1, end));
}
P print(VP& tree, int node, int start, int end, int left, int right) {
	P temp(0, 0);
	if (left > end || right < start) return temp;
	if (left <= start && end <= right)  return tree[node];
	int m = (start + end) / 2;
	return MIN_MAX(print(tree, node * 2, start, m, left, right), print(tree, node * 2 + 1, m + 1, end, left, right));
}
int main() {
	int n, m, v, l, r;
	scanf("%d%d",&n, &m);
	vector<int> vec(n + 1);
	LOP(i, n) {
		scanf("%d",&vec[i]);
	}
	int h = ceil(log2(n));
	VP tree(1 << (h + 1), make_pair(0, 0));
	init(tree, vec, 1, 1, n);
	LOP(i, m) {
		scanf("%d%d", &l, &r);
		P result = print(tree, 1, 1, n, l, r);
		printf("%d %d\n", result.first, result.second);
	}
	return 0;
}
