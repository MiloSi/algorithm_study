#pragma warning (disable: 4996)
#include<cstdio>
#include<queue>
#include<algorithm>
#include<utility>
#include<functional>
#include<vector>
using namespace std;
typedef pair<int, int> PI;
typedef tuple<int, int, int> TI;
priority_queue < PI, vector<PI>, greater<PI>> pq;
int n, e, a, b, c;
vector<vector<PI>> node;
vector<bool> visited;
vector<PI> cost;
const int INF = 0x1fffffff;
void dijkstra(int k) {
	pq.push(make_pair(0, k));
	cost[k].first = 0;
	cost[k].second = 0;
	int n_size = n-1;

	while (n_size && pq.size()) {
		PI p = pq.top();
		pq.pop();
		if (visited[p.second]) continue;
		visited[p.second] = true;
		n_size--;
		for (auto i : node[p.second]) {
			if (cost[i.first].first > i.second + p.first) {
				cost[i.first].first = i.second + p.first;
				cost[i.first].second = p.second;
				if (!visited[i.first]) {
					pq.push(make_pair(cost[i.first].first, i.first));
				}
			}
		}
	}
}
void _clear() {
	visited.clear();
	visited.resize(n + 1);
	cost.clear();
	cost.resize(n + 1, make_pair(INF, -1));
}
PI getMin(int a, int b, int a1, int b1) {
	PI p;
	if (a < b) {
		p = { a, a1 };
	}
	else {
		p = { b, b1 };
	}
	return p;
}
int getRoute(int f1, int f2, int f3) {
	int sum = 0;
	dijkstra(f1);
	sum = cost[f2].first;
	_clear();
	dijkstra(f2);
	sum += cost[f3].first;
	_clear();
	dijkstra(f3);
	sum += cost[n].first;
	_clear();
	return sum;
}
int main() {
	scanf("%d%d", &n, &e);
	node.resize(n + 1);
	visited.resize(n + 1);
	cost.resize(n + 1, make_pair(INF,-1));
	for (int i = 0; i < e; i++) {
		scanf("%d%d%d", &a, &b, &c);
		node[a].push_back(make_pair(b, c));
		node[b].push_back(make_pair(a, c));
	}
	scanf("%d%d", &a, &b);
	int sum = min(getRoute(1, a, b), getRoute(1, b, a));

	if (sum >= INF)
		printf("-1\n");
	else
		printf("%d\n", sum);
	return 0;
}