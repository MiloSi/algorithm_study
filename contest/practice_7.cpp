#include <string>
#include <vector>
#include <queue>
using namespace std;
bool visited[20001];

int solution(vector<string> strs, string t)
{
	int answer = 0, len, s_size = strs.size(), t_len = t.length(), q_size, idx;
	bool checked;
	queue<int> q;
	q.push(0);

	while (q.size()) {
		q_size = q.size();
		while (q_size) {
			idx = q.front();
			q.pop();
			for (int i = 0; i < s_size; i++) {
				len = strs[i].length();
				if (idx + len > t_len) continue;
				checked = true;
				for (int j = 0; j < len; j++) {
					if (strs[i].at(j) != t.at(idx + j)) {
						checked = false;
						break;
					}
				}
				if (checked) {
					if (len + idx == t_len) return ++answer;
					if (!visited[idx + len]) {
						visited[idx + len] = true;
						q.push(idx + len);
					}
				}
			}
			q_size--;
		}
		answer++;
	}
	return -1;
}