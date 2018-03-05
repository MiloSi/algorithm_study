#include<iostream>
#include<memory.h>
using namespace std;
const int NUM_MAX = 100;

int solution() {
	int n;
	cin >> n;

	bool* visited = new bool[n * NUM_MAX + 1];
	int* space = new int[n * NUM_MAX + 1];
	int len = 1;

	memset(visited, false, sizeof(bool) * n * NUM_MAX + 1);
	memset(space, 0, sizeof(int) * n * NUM_MAX + 1);
	space[0] = 0;
	visited[0] = true;
	
	for (int i = 0; i < n; ++i) {
		int point;
		cin >> point;

		int tmp = len;
		for (int j = 0; j < tmp; ++j) {
			int enablePoint = space[j] + point;
			if (visited[enablePoint] == false) {
				visited[enablePoint] = true;
				space[len] = enablePoint;
				++len;
			}
		}
	}

	delete[] visited;
	delete[] space;
	return len;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cout << "#" << test_case << " " << solution() << endl;
	}
	return 0;
}
