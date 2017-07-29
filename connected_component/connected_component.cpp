#include <iostream>
#include <memory.h>
using namespace std;

bool table[1001][1001];
bool visited[1001];

int n, m;
int result = 0;
void dfs(int v, bool isOne) {
	visited[v] = true;

	for (int i = 1; i <= n; i++) {
		if (table[v][i] && !visited[i]) {
			if(isOne) {
				isOne = false;
				result++;
			}
			dfs(i,false);
			
		}
	}

}
int main() {
	int u, v;
	cin >> n >> m;

	memset(table, false, sizeof(table));
	memset(visited, false, sizeof(visited));

	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		table[u][v] = true;
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs(i, true);
		}
	}
	cout << result << endl;
	return 0;

}