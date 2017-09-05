#include <iostream>
#include <vector>
using namespace std;
inline int getData(int *arr) {
	if (arr[0] == arr[1]) return arr[2];
	else if (arr[0] == arr[2]) return arr[1];
	else return arr[0];
}
vector<int> solution(vector<vector<int> > v) {
	int x[3], y[3];
	for (int i = 0; i < v.size(); i++) {
		x[i] = v[i][0];
		y[i] = v[i][1];
	}
	vector<int> ans;
	ans.push_back(getData(x));
	ans.push_back(getData(y));
	return ans;
}