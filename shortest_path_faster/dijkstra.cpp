#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int t, n, m, a, b;
long long int ans;
int st, ed , w;
#define MAXS  0x7fffffffff
typedef struct _Node {
	int to;
	long long int w;
}node;
node make_node(int a, int b) {
	node nodes = { a,b };
	return nodes;
}
vector<vector<node > > v;
vector<long long int> costs;
vector<bool> visited;
struct myrule {
	bool operator()(node a, node b) {
		return a.w > b.w;
	}
};


void dijkstra() {
	priority_queue<node, vector<node>, myrule> pq;
	costs[a] = 0;
	pq.push(make_node(a, 0));
	int n_size = n;
	while (pq.size() && n_size > 0) {
		node nd = pq.top();
		pq.pop();
		if (visited[nd.to] == true) continue;
		visited[nd.to] = true;
		n_size--;
		
		for(int j = 0; j < v[nd.to].size(); j++){
			node i = v[nd.to][j];
			if (!visited[i.to]) {
				if (costs[i.to] > costs[nd.to] + i.w) {
					costs[i.to] = costs[nd.to] + i.w;
					pq.push(make_node(i.to, costs[i.to]));
				}
			}
		}
	}
}


int main() {
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n >> m >> a >> b;
		v.resize(n + 1);
		costs.resize(n + 1, MAXS);
		visited.resize(n + 1);
		for (int i = 0; i < m; i++) {
			cin >> st >> ed >> w;
			v[st].push_back(make_node(ed, w));
			v[ed].push_back(make_node(st, w));
		}
		dijkstra();
		cout << "#" << tc << " " << costs[b] << endl;
		v.clear();
		costs.clear();
		visited.clear();
	}
}
