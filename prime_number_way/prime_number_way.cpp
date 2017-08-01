#include <iostream>
#include <array>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#define MAX_SIZE 10000
using namespace std;
vector<int> *graph;
bool *visited;
int result;

typedef struct _Node {
	int v;
	int w;
}node;


bool m_Compare(int a, int b) {
	int t = 0;
	int a1, b1;

	for (int i = 0; i < 4; i++) {
		a1 = a % 10;
		b1 = b % 10;
		if (a1 != b1)
			t++;
		if (t > 1)
			return false;
		a = a / 10;
		b = b / 10;
	}
	if(t == 1)
		return true;
	return false;
}
void bfs(int start, int end) {
	if (start == end) {
		result = 0;
		return;
	}
	queue<node> q;
	node nd = { start, 0 };
	visited[start] = true;
	q.push(nd);

	while (q.size()) {
		nd = q.front();
		q.pop();

		for (int i = 0; i < graph[nd.v].size(); i++) {
			int ed = graph[nd.v].at(i);

			if (ed == end) {
				result = nd.w + 1;
				return;
			}
			if (!visited[ed]) {
				visited[ed] = true;
				node nd1 = { ed, nd.w +1};
				q.push(nd1);
			}
		}
	}
}
int main() {
	int n;
	int x, y;
	int index = 0;

	array<bool, MAX_SIZE> prime_number;
	vector<int> v;
	map<int, int> m;

	prime_number.fill(true);
	//소수 처리
	for (int i = 2; i < MAX_SIZE; i++) {
		if (prime_number[i]) {
			for (int j = i * 2; j < MAX_SIZE; j = j + i) {
				prime_number[j] = false;
			}
			//1000보다 큰 소수는 벡터로 저장
			if (i > 1000) {
				m.insert(map<int, int>::value_type(i, index++));
				v.push_back(i);
			}
		}
	}
	// 그래프 만들기
	const int v_size = v.size();
	// 각 소수를 그래프로 연결
	graph = new vector<int>[v_size];
	for (int i = 0; i < v_size; i++) {
		for (int j = i + 1; j < v_size; j++) {
			if (m_Compare(v[i], v[j])) {
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
	}
	cin >> n;
	while (n--) {
		visited = new bool[v_size];
		fill_n(visited, v_size, false);
		result = -1;
		cin >> x >> y;

		bfs(m.find(x)->second, m.find(y)->second);

		if (result == -1)
			cout << "Impossible" << endl;
		else 
			cout << result << endl;

		delete[] visited;
	}
	delete[] graph;
	return 0;
}