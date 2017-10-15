#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef struct Person {
	int a, b, seq, state;
	int times;
}person;
vector<person> people;
int desks[10];
int repairs[10];
struct myRule {
	bool operator()(person a, person b) {
		if (a.seq == b.seq) {
			if (a.b != 0)
				return a.b > b.b;
			else
				return a.a > b.a;
		}
		return a.seq > b.seq;
	}
};
struct myGreater {
	bool operator()(int a, int b) {
		return a > b;
	}
};
typedef struct _Processing{
	queue<person> waiting;
	priority_queue < person, vector<person>, myRule> working;
	priority_queue <int, vector<int>, myGreater> idle;
}process;
int t, n, m, k, a, b, ans;
void time_flow(process &w) {
	int w_size =  w.waiting.size();
	for (int i = 0; i < w_size; i++) {
		person p = w.waiting.front();
		w.waiting.pop();
		p.seq++;
		w.waiting.push(p);
	}
}


void simulation() {
	process w1, w2;
	queue<person> q;
	for (int i = 1; i <= k; i++)
		q.push(people[i]);
	for (int i = 1; i <= n; i++)
		w1.idle.push(i);
	for (int i = 1; i <= m; i++)
		w2.idle.push(i);


	int times = 0;
	int nums = k;
	while (nums > 0) {
		int w2_size = w2.working.size();
		while (w2_size-- > 0) {
			person p1 = w2.working.top();
			w2.working.pop();
			p1.times--;
			p1.seq++;
			if (p1.times <= 0) {
				if (w2.waiting.size() > 0) {
					person p2 = w2.waiting.front();
					w2.waiting.pop();
					p2.b = p1.b;
					p2.times = repairs[p2.b];
					p2.seq++;
					if (p2.a == a && p2.b == b) ans += p2.state;
					nums--;
					if (nums <= 0) return;
					w2.working.push(p2);
				}
				else {
					w2.idle.push(p1.b);
				}
			}
			else {
				w2.working.push(p1);
			}
		}
		time_flow(w2);
		int w1_size = w1.working.size();
		while (w1_size-- > 0) {
			person p1 = w1.working.top();
			w1.working.pop();
			p1.times--;
			p1.seq++;
			if (p1.times <= 0) {
				if (w1.waiting.size() > 0) {
					person p2 = w1.waiting.front();
					w1.waiting.pop();
					p2.a = p1.a;
					p2.times = desks[p2.a];
					p2.seq++;
					w1.working.push(p2);
				}
				else {
					w1.idle.push(p1.a);
				}

				if (w2.idle.size() > 0) {
					p1.b = w2.idle.top();
					w2.idle.pop();
					p1.times = repairs[p1.b];
					if (p1.a == a && p1.b == b) ans += p1.state;
					nums--;
					if (nums <= 0) return;
					w2.working.push(p1);
				}
				else {
					w2.waiting.push(p1);
				}
			}
			else {
				w1.working.push(p1);
			}
		}
		time_flow(w1);
		int q_size = q.size();
		while (q_size-- > 0) {
			person p1 = q.front();
			p1.seq++;
			q.pop();
			if (p1.times <= times) {
				if (w1.idle.size() > 0) {
					p1.a = w1.idle.top();
					w1.idle.pop();
					p1.times = desks[p1.a];
					w1.working.push(p1);
				}
				else {
					w1.waiting.push(p1);
				}
			}
			else {
				q.push(p1);
			}
		}
		times++;
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		ans = 0;
		cin >> n >> m >> k >> a >> b;
		people.resize(k+1);
		for (int i = 1; i <= n; i++) {
			cin >> desks[i];
		}
		for (int i = 1; i <= m; i++) {
			cin >> repairs[i];
		}
		for (int i = 1; i <= k; i++) {
			people[i].state = i;
			cin >> people[i].times;
		}
		simulation();
		if (ans == 0) ans = -1;

		cout << "#" << tc << " " << ans << endl;
		people.clear();
	}

}