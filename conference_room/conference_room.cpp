#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

bool check(pair<int, int> a, pair<int, int> b) {

	return a.second < b.second;
}


int main() {
	int n;
	int w = 1;
	int index = 0;
	cin >> n;
	pair<int, int> con[100000];

	for (int i = 0; i < n; i++)
	{
		cin >> con[i].first >> con[i].second;
	}
	sort(con, con + n, check);

	for (int i = 1; i < n; i++)
	{
		if (con[index].second <= con[i].first)
		{
			w++;
			index = i;
		}
	}

	cout << w << endl;

	return 0;
}