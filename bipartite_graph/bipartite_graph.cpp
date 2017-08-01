#include <iostream>
#include <vector>
#include <array>
#include <queue>
using namespace std;


typedef array<bool, 20001> mVisited;
typedef array<int, 20001> mType;
typedef vector<int> myarr;


mType type;
myarr arr[20001];
mVisited visited = { false };

int k, v, e;
bool dfs(int i, int myType) {
	visited[i] = true;
	type[i] = myType;
	bool checked = true;
	queue<int> q;

	q.push(i);

	while(q.size()) {
		i = q.front();
		myType = type[i];
		q.pop();
		for (auto j : arr[i]) {
			if (type[j] == myType)
				return false;

			if (!visited[j]) {
				visited[j] = true;
				if (myType == 1)
					type[j] = 2;
				else
					type[j] = 1;
				q.push(j);
			}
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int y, x;
	bool result;

	cin >> k;
	while (k--) {
		cin >> v >> e;

		for (int i = 1; i <= v; i++) {
			arr[i].clear();
			visited[i] = false;
			type[i] = 0;
		}

		for (int i = 0; i < e; i++) {
			cin >> y >> x;
			arr[y].push_back(x);
			arr[x].push_back(y);
		}

		result = true;
		for (int i = 1; i <= v; i++) {
			if (!visited[i]) {
				if (!dfs(i, 1)) {
					result = false;
					break;
				}
			}
		}
		if (result) {
			cout << "YES" << endl;
		}
		else { cout << "NO" << endl; }
		

	}
	return 0;
}



