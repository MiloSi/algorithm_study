#include<vector>
using namespace std;
int dp[1000][1000];

inline int _Min(int a, int b) {
	return a < b ? a : b;
}
inline int _Min(int a, int b, int c) {
	int d = _Min(a, b);
	return c < d ? c : d;
}
int solution(vector<vector<int>> board)
{
	int answer = 0;
	for (int i = 0; i < board[0].size(); i++) {
		dp[0][i] = board[0][i];
		if (answer < dp[0][i]) answer = dp[0][i];
	}
	for (int i = 0; i < board.size(); i++) {
		dp[i][0] = board[i][0];
		if (answer < dp[i][0]) answer = dp[i][0];
	}

	for (int i = 1; i < board.size(); i++) {
		for (int j = 1; j < board[i].size(); j++) {
			if (board[i][j]) {
				dp[i][j] = _Min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
				if (dp[i][j] != 0) dp[i][j]++;
				else dp[i][j] = 1;
				if (dp[i][j] > answer) answer = dp[i][j];
			}
		}
	}
	answer = answer* answer;
	return answer;
}