#include <iostream>
#include <queue>
#include <array>
#include <utility>
using namespace std;

typedef array<array<bool, 101>, 101>	 my_array;
typedef array<bool, 101> my_visited;

my_array arr;
my_visited visited = { false, };

int n, m;
int result = -1;
int from, to;

#define LOP(i, j, k) for(int i = j; i <= k; i++)


void bfs() {
	int y = from;
	pair<int, int> p = { from, 0 };

	visited[y] = true;
	queue<pair<int, int>> q;
	q.push(p);

	while (q.size()) {
		p = q.front();
		q.pop();

		LOP(i, 1, n) {
			if (arr[p.first][i] == true && !visited[i]) {
				if (i == to) {
					result = p.second + 1;
					return;
				}

				visited[i] = true;
				pair<int, int> p1 = { i, p.second + 1 };
				q.push(p1);
			}
		}

	}
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int y, x;
	cin >> n >> from >> to >> m;

	LOP(i, 1, m) {
		cin >> y >> x;
		arr[y][x] = arr[x][y] = true;
	}
	bfs();

	cout << result <<endl;
	return 0;
}