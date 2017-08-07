#include <iostream>
#include <vector>
using namespace std;
vector<int> vec[10001];
int weight[10001];
bool visited[10001];
int n, m, _Max = 0;
int dfs(int x) {
	int w = 1;
	visited[x] = true;
	for (auto i : vec[x]) {
		if (!visited[i]) {
			visited[i] = true;
			w += dfs(i);
		}
	}
	return w;
}
int main() {
	int u, v;

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		vec[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			visited[j] = false;
		}
		weight[i] = dfs(i);
		if (weight[i] > _Max)
			_Max = weight[i];
	}
	for (int i = 1; i <= n; i++) {
		if (weight[i] == _Max) cout << i << " ";
	}
	cout << endl;
	return 0;
}