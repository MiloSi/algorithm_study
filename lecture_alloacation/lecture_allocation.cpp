#pragma warning (disable: 4996)
#include <cstdio>
#include <algorithm>
using namespace std;
pair<int, int> st[400000];
int max = 0;
bool rule(pair<int, int>a, pair<int, int> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first < b.first;
}

int main() {
	int n, result = 0;
	bool canChange = false;;
	scanf("%d",&n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &st[i * 2].first, &st[i * 2 + 1].first);
		st[i * 2].second = 1;
		st[i * 2 + 1].second = -1;
	}
	sort(st, st + n*2, rule);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += st[i].second;
		if (result < sum) result = sum;
	}
	printf("%d\n", result);
	return 0;
}