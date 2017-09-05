#include<vector>
using namespace std;
inline int _Max(int a, int b) {
	return a > b ? a : b;
}
inline int _Max(int a, int b, int c, int d) {
	a = _Max(a, b);
	b = _Max(c, d);
	return a > b ? a : b;
}
inline int getMax(int c, int* arrs) {
	int result = 0;
	for (int i = 0; i < 4; i++) {
		if (c == i) continue;
		if (result < arrs[i]) result = arrs[i];
	}
	return result;
}
int solution(vector<vector<int> > land)
{
	int arrs[2][4];
	for (int i = 0; i < 4; i++) {
		arrs[1][i] = arrs[0][i] = land[0][i];
	}
	for (int i = 1; i < land.size(); i++) {
		for (int j = 0; j < 4; j++) {
			arrs[1][j] = land[i][j] + getMax(j, arrs[0]);
		}
		for (int j = 0; j < 4; j++) {
			arrs[0][j] = arrs[1][j];
		}
	}
	int answer = _Max(arrs[1][0], arrs[1][1], arrs[1][2], arrs[1][3]);

	return answer;
}