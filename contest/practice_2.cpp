#include<vector>
using namespace std;
bool visited[100001];
bool solution(vector<int> arr)
{
	bool answer = true;
	for (int i = 0; i< arr.size(); i++) {
		if (visited[arr[i]] || arr[i] > arr.size()) return false;
		visited[arr[i]] = true;
	}
	return answer;
}