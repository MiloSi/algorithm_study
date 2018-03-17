#pragma warning (disable:4996)
//Network Flow Study
#include <cstdio>
#include <vector>
#include <algorithm>
#define input2(a,b) scanf("%d%d",&a,&b);
#define input(a) scanf("%d",&a);
using namespace std;

const int MAX_NUM = 1001;
const int NOT_IN = -1;
int worker[MAX_NUM];
int works[MAX_NUM];
bool visited[MAX_NUM];
vector<int> adj[MAX_NUM];
bool dfs(int idx) {
	visited[idx] = true;

	for (auto i : adj[idx]) {
		if (!works[i] || visited[works[i]] == false && dfs(works[i])) {
			works[i] = idx;
			worker[idx] = i;
			return true;
		}
	}	
	return false;
}
int main() {
	int N, M, ans = 0;

	input2(N, M);

	for (int i = 1; i <= N; i++) {
		int K;
		input(K);
		for (int j = 0; j < K; j++) {
			int k;
			input(k);
			adj[i].push_back(k);
		}
	}
	for (int i = 1; i <= N; i++) {
		if (worker[i] == 0) {
			fill(visited, visited + MAX_NUM, 0);
			if (dfs(i)) ans++;
		}
	}
	printf("%d\n", ans);
}
