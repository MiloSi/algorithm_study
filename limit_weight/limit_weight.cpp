#pragma warning(disable : 4996)
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
vector<pair<int, int>> vec[100010];
bool visited[100010];
int minW = 0x7fffffff, maxW = 0;
int result;
int from, to;
int n, m;
queue<int> q;
bool bfs(int w) {
	int s = from;
	fill_n(visited,10001,false);
	while (q.size()) q.pop();
	visited[s] = true;
	q.push(s);
	while (!q.empty()) {
		s = q.front();
		q.pop();
		if (s == to) return true;
		for (int i = 0; i < vec[s].size(); i++) {
			 pair<int, int> p = vec[s][i];
			 if (!visited[p.first] && w <= p.second)
			 {
				 q.push(p.first);
				 visited[p.first];
			 }
		}
	}
	return false;
}	
void binary_search() {
	int f = 0, t = maxW;
	int mid;
	result = 0;
	while (f <= t) {
		mid = (f + t) / 2;
		if (bfs(mid)) {
			result = mid;
			f = mid + 1;

		}
		else {
			t = mid - 1;
		}
	}
}
int main() {
	int v, u,w;

	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++) {
		scanf("%d %d %d", &v, &u, &w);
		vec[v].push_back(pair<int, int>(u, w));
		vec[u].push_back(pair<int, int>(v, w));
		if (maxW < w) maxW = w;
		if (minW > w) minW = w;
	}
	scanf("%d %d", &from, &to);
	binary_search();
	printf("%d\n", result);
	return 0;
}


