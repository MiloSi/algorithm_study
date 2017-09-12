#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class list {
public:
	int f, t, w;
	bool operator()(list i, list j) { return i.w < j.w; }
};
int disjoint(int x, vector<int> &uf) {
	return (x != uf[x]) ? uf[x] = disjoint(uf[x], uf) : x;
}

int main() {
	int n, m;

	cin >> n >> m;

	vector <int> uf(n + 1);
	vector <list> v(m);

	for (int i = 1; i <= n; i++) uf[i] = i;
	for (int i = 0; i < m; i++)
		cin >> v[i].f >> v[i].t >> v[i].w;
	sort(v.begin(), v.end(), list());
	int ans = 0;
	for (int i = 0; i < m; i++)
		if (disjoint(v[i].f, uf) != disjoint(v[i].t, uf)) {
			uf[disjoint(v[i].t, uf)] = uf[v[i].f];
			ans += v[i].w;
		}
	cout << ans << endl;
	return 0;
}
