#pragma warning (disable:4996)
//Network Flow Study
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define input(a,b) scanf("%d%d",&a,&b);
using namespace std;

const int MAX_NUM = 401;
const int NOT_IN = -1;
const int VERY_BIG = 100000000;

int capacity[MAX_NUM][MAX_NUM];
int flow[MAX_NUM][MAX_NUM];
int previous[MAX_NUM];
vector<int> adj[MAX_NUM];
int main() {
	int N, P;
	input(N, P);
	for (int i = 0; i < P; i++) {
		int u, v;
		input(u, v);
		capacity[u][v] = 1;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int start = 1, end = 2,  total = 0;


	while (1) {
		queue<int> q;
		q.push(start);
		fill(previous, previous + MAX_NUM, NOT_IN);
		while (q.size()) {
			int curr = q.front();
			q.pop();
			for (auto next : adj[curr]) {
				if (capacity[curr][next] > flow[curr][next] && previous[next] == NOT_IN) {
					q.push(next);
					previous[next] = curr;
					if (next == end) break;
				}
			}
		}
		if (previous[end] == NOT_IN) break;

		int value = VERY_BIG;

		for (int i = end; i != start; i = previous[i]) {
			value = min(value, capacity[previous[i]][i] - flow[previous[i]][i]);
		}
		for (int i = end; i != start; i = previous[i]) {
			if (capacity[previous[i]][i] - flow[previous[i]][i] > 0) {
				flow[previous[i]][i] = 1;
				flow[i][previous[i]] = -1;
			}
		}
		total += value;
	}
	printf("%d", total);

}
