#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int MAX = 1000000;
int t_size, p_size;
vector<int> getPI(string p) {
	vector<int> pi(p_size,0);
	for (int i = 1, j = 0; i < p_size; i++) {
		while (j > 0 && p.at(i) != p.at(j)) {
			j = pi[j - 1];
		}
		if (p.at(i) == p.at(j)) {
			pi[i] = ++j;
		}
	}
	return pi;
}
vector<int> tmp(string& t, string& p) {
	vector<int> result, pi;
	pi = getPI(p);
	for (int i = 0, j = 0; i < t_size; i++) {
		while (j > 0 && t.at(i) != p.at(j)) j = pi[j - 1];
		if (t.at(i) == p.at(j)) {
			if (j == p_size - 1) {
				result.push_back(i - p_size + 2);
				j = pi[j];
			}
			else j++;
		}

	}
	return result;
}
int main() {
	string t, p;
	getline(cin, t);
	getline(cin, p);
	t_size = t.length();
	p_size = p.length();

	auto result = tmp(t, p);
	printf("%d\n", result.size());
	for(auto i : result)
		printf("%d ", i);
	return 0;
}

