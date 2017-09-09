#pragma warning (disable: 4996)
#include<cstdio>
#include<queue>
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
const int INF = 0x5fffffff;
void dijkstra(int k) {
	pq.push(make_pair(0, k));
	visited[k] = true;
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
					visited[i.first] = true;
					pq.push(make_pair(cost[i.first].first, i.first));
				}
			}
		}
	}
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
	dijkstra(1);
	int t = 0;
	for (int j = n - 1; j != 0; j = cost[j].second) {
		if (j == a || j == b) t++;
	}
	if (t == 2) {
		printf("%d\n", cost[n - 1].first);
		return 0;
	}
	return 0;
}