#pragma warning(disable : 4996)
#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
#define PI pair<int,int>
vector<vector<PI>> node;
vector<bool> visited;
vector<int> cost;
int n, m, f, t, w;

const int INF = 0x6ffffff;
priority_queue<PI, vector<PI>, greater<PI>> pq;
void dijkstra(int from) {
	pq.push(make_pair(0, from));
	cost[from] = 0;
	while (pq.size() && n) {
		PI pi = pq.top();
		pq.pop();
		if (visited[pi.second]) continue;
		visited[pi.second];
		n--;
		for (auto i : node[pi.second]) {
			if (cost[i.first] > cost[pi.second] + i.second) {
				cost[i.first] = cost[pi.second] + i.second;
				if (!visited[i.first]) {
					pq.push(make_pair(cost[i.first], i.first));
				}
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	node.resize(n + 1);
	visited.resize(n + 1);
	cost.resize(n + 1, INF);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &f, &t, &w);
		node[f].push_back(make_pair(t,w));
	}
	scanf("%d%d", &f, &t);
	dijkstra(f);
	printf("%d\n", cost[t]);
	return 0;
}