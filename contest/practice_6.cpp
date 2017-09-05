#include <vector>
using namespace std;
inline int _Max(int a, int b) {
	return a > b ? a : b;
}
inline int _Max(int a, int b, int c) {
	b = _Max(b, c);
	return a > b ? a : b;
}
inline int _Max(int *arr1, int *arr2) {
	int a = _Max(arr1[0], arr1[1]);
	int b = _Max(arr2[0], arr2[1]);
	return a > b ? a : b;
}
inline int _Max(int *arr1, int *arr2, int c) {	
	int a = _Max(arr1[2], arr1[3]);
	int b = _Max(arr2[2], arr2[3]);
	return a > b ? a : b;
}
inline int _Max(int *arr1) {
	int a = _Max(arr1[0], arr1[1]);
	int b = _Max(arr1[2], arr1[3]);
	return a > b ? a : b;
}
int dp[3][4];
int solution(vector<int> sticker)
{
	dp[2][0] = dp[0][0] = sticker[0];
	if (sticker.size() > 1)
		dp[2][2] = dp[1][2] = sticker[1];

	for (int i = 2; i< sticker.size() - 1; i++) {
		dp[2][0] = sticker[i] + _Max(dp[0][0], dp[0][1], dp[1][1]);
		dp[2][1] = _Max(dp[0], dp[1]);
		dp[2][2] = sticker[i] + _Max(dp[0][2], dp[0][3], dp[1][3]);
		dp[2][3] = _Max(dp[0], dp[1], 1);

		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 4; k++) {
				dp[j][k] = dp[j + 1][k];
			}
		}
	}
	dp[2][2] = sticker[sticker.size() - 1] + _Max(dp[0][2], dp[0][3]);
	dp[2][3] = _Max(dp[0], dp[1], 1);
	int answer = _Max(dp[2]);
	return answer;
}