#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define LOP(i, n) for(int i= 0; i < n; i++)
#define PII pair<int ,int>
int arr[100][100];
unsigned long long int dp[100][100];
bool visited[100][100];
int n;
int yf[2] = { 0,1 };
int xf[2] = { 1,0 };
void bfs() {
	queue<PII> q;
	int y, x;
	q.push(PII(0, 0));
	while (q.size()) {
		PII p = q.front();
		q.pop();
		if (p.first == n - 1 && p.second == n - 1) return;
		int move = arr[p.first][p.second];
		if (p.first + move <= n - 1) dp[p.first + move][p.second] += dp[p.first][p.second];
		if (p.second + move <= n - 1) dp[p.first][p.second + move] += dp[p.first][p.second];
		LOP(i, 2) {
			y = p.first + yf[i];
			x = p.second + xf[i];
			if (y == n || x == n) continue;
			if (!visited[y][x]) {	
				visited[y][x] = true;
				q.push(PII(y, x));
			}
		}
	}
}
int main() {
	cin >> n;
	LOP(i, n) LOP(j, n) cin >> arr[i][j];
	dp[0][0] = 1;
	bfs();
	LOP(i, n) {
		LOP(j, n)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}

	cout << dp[n - 1][n - 1] << endl;
	return 0;

}
