#pragma warning (disable:4996)
#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
int tc, n, ans;
int arr[10][10];

typedef struct _Person {
	int y, x;
	int dest;
	int times, state, seq;
}person;
typedef struct _Stair {
	int y, x;
	int nums, times;
}stair;
typedef struct myRule {
	bool operator()(person a, person b) {
		if (a.seq == b.seq) {
			return a.state < b.state;
		}
		return	a.seq > b.seq;
	}
};


void game(vector<person> people, vector<stair> stairs) {
	//queue<person> q;
	priority_queue<person, vector<person>, myRule> pq;

	for (int i = 0; i < people.size(); i++) {
		if (people[i].dest == 0) {
			people[i].times = abs(people[i].y - stairs[0].y) + abs(people[i].x - stairs[0].x);
		}
		else 
			people[i].times = abs(people[i].y - stairs[1].y) + abs(people[i].x - stairs[1].x);
		pq.push(people[i]);
	}
	int time = 0;
	while (pq.size()) {
		int q_size = pq.size();
		while (q_size--) {
			person p = pq.top();
			pq.pop();
			if (p.state == 0) {
				if (p.times <= time) {
					p.state = -1;
				}
				p.seq++;
				pq.push(p);
			}
			else if (p.state == -1) {
				if (stairs[p.dest].nums < 3) {
					stairs[p.dest].nums++;
					p.state = 1;
					p.times = stairs[p.dest].times;
				}
				p.seq++;
				pq.push(p);
			}
			else {
				p.times--;
				p.seq++;
				if (p.times == 0) {
					stairs[p.dest].nums--;
				}
				else {
					pq.push(p);

				}
			}
		}
		if (pq.size() == 0) break;
		time++;
	}
	if (ans > time)  ans = time;
}



void simulation(vector<person> people, vector<stair> stairs, int cases) {
	for (int cs = 0; cs < cases; cs++) {
		for (int i = 0; i < people.size(); i++) {
			int dest = 1 << i;
			int c = dest&cs;
			if (c == dest)
				people[i].dest = 1;
			else people[i].dest = 0;
		}
		game(people, stairs);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "r", stdin);


	cin >> tc;
	for (int ts = 1; ts <= tc; ts++) {
		cin >> n;
		ans = 0x7777;
		vector<person> people;
		vector<stair> stairs;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == 1) {
					person p = { i, j, 0, 0, 0, 0};
					people.push_back(p);
				}
				if (arr[i][j] > 1) {
					stair s = { i, j, 0, arr[i][j] };
					stairs.push_back(s);
				}
			}
		}
		int p_size = people.size();
		int cases = 1 << (p_size);
		simulation(people, stairs, cases);
		cout << "#" << ts << " " << ans << endl;
	}


	return 0;
}