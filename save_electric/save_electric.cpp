#pragma warning (disable : 4996)
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
class list {
public : 
	int f, t, w;
	bool operator()(list a, list b) {
		return a.w < b.w;
	}
};
int join[200000];
vector<list> v(200000);
int m, n;
int disjoint(int i) {
	return (join[i] != i) ? join[i] = disjoint(join[i]) : i;
}
int main() {
	while (1) {
		int cost = 0;
		int w = 0;
		scanf("%d%d", &m, &n);
		if (m == 0 && n == 0) break;

		for (int i = 0; i < m; i++) join[i] = i;
		for (int i = 0; i < n; i++) {
			scanf("%d%d%d", &v[i].f, &v[i].t, &v[i].w);
			cost += v[i].w;
		}
		sort(v.begin(), v.begin() + n, list());
		for (int i = 0; i < n; i++) {
			if (disjoint(v[i].f) != disjoint(v[i].t)) {
				join[disjoint(v[i].t)] = join[v[i].f];
				w += v[i].w;
			}
		}
		printf("%d\n", cost - w);
	}
	return 0;
}