#include <vector>
#include <iostream>
#include <queue>
using namespace std;
typedef struct _Node {
	int y, x;
}Node;
bool visited[100][100];

int yv[4] = { -1,1,0,0 };
int xv[4] = { 0,0,-1,1 };

void bfs(int y, int x, int n, int m, int color, vector<vector<int>>& pictures, int &ms) {
	int w = 1;
	Node nd = { y, x };
	visited[y][x] = true;
	queue<Node> q;
	q.push(nd);
	while (q.size()) {
		Node nd1 = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			y = nd1.y + yv[i];
			x = nd1.x + xv[i];
			if (y < 0 || y >= n || x < 0 || x >= m) continue;
			if (pictures[y][x] == color && !visited[y][x]) {
				visited[y][x] = true;
				w++;
				Node nd2 = { y,x };
				q.push(nd2);
			}
		}
	}
	if (ms < w) {
		ms = w;
	}
}


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;
	for (int i = 0; i < n; i++) {
		fill(visited[i], visited[i] + m, false);
	}
	vector<int> answer(2);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (picture[i][j] != 0 && !visited[i][j]) {
				number_of_area++;
				bfs(i, j, n, m, picture[i][j], picture, max_size_of_one_area);
			}
		}
	}
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}
int main() {
	int m, n, x;
	cin >> m >> n;
	vector<vector<int>> v(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> x;
			v[i].push_back(x);
		}
	}
	vector<int> s = solution(m, n, v);
	cout << s[0] << " " << s[1] << endl;
	system("pause");
	return 0;

}