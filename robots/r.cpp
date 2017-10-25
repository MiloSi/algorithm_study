#include <iostream>
using namespace std;
struct robot {
	int x, y, dir;
	char d;
};
struct order {
	int num;
	char o;
	int s;
};
struct result {
	int errors, who, whom;
};

robot robots[101];
order orders[101];
int a, b, n, m; //가로 세로 로봇 명령
int yv[4] = { 1,0,-1,0 };
int xv[4] = { 0,1,0,-1 };
char dir[4] = { 'N','E','S','W' };



result simulation(const order o) {
	result situation = {0,0,0};
	robot &r = robots[o.num];
	if (o.o == 'F') {
		int toX, toY;
		toX = r.x + xv[r.dir] * o.s;
		toY = r.y + yv[r.dir] * o.s;

		bool isOkay = true;
		switch (r.dir)
		{
		case 0:
			for (int i = 1; i <= n; i++) {
				if (o.num == i) continue;
				if (r.x == robots[i].x && toY >= robots[i].y && r.y < robots[i].y) {
					situation = { 1, o.num, i };
					toX = robots[i].x;
					toY = robots[i].y;
					isOkay = false;
				}
			}
			break;
		case 1:
			for (int i = 1; i <= n; i++) {
				if (o.num == i) continue;
				if (r.y == robots[i].y && toX >= robots[i].x && r.x < robots[i].x) {
					situation = { 1, o.num, i };
					toX = robots[i].x;
					toY = robots[i].y;
					isOkay = false;
				}
			}
			break;
		case 2:
			for (int i = 1; i <= n; i++) {
				if (o.num == i) continue;
				if (r.x == robots[i].x && toY <= robots[i].y && r.y > robots[i].y) {
					situation = { 1, o.num, i };
					toX = robots[i].x;
					toY = robots[i].y;
					isOkay = false;
				}
			}
			break;
		case 3:
			for (int i = 1; i <= n; i++) {
				if (o.num == i) continue;
				if (r.y == robots[i].y && toX <= robots[i].x && r.x > robots[i].x) {
					situation = { 1, o.num, i };
					toX = robots[i].x;
					toY = robots[i].y;
					isOkay = false;
				}
			}
			break;
		}
		if (!isOkay) return situation;

		if (toX <= 0 || toX > a || toY <= 0 || toY > b) {
			situation = { 2, o.num };
			return situation;
		}
		r.x = toX; r.y = toY;
	}
	else if (o.o == 'R') {
		r.dir = (r.dir + o.s) % 4;
		r.d = dir[r.dir];
	}
	else {
		r.dir = (r.dir+100 - o.s) % 4;
		r.d = dir[r.dir];
	}
	return situation;
}

int main() {
	cin >> a >> b >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> robots[i].x >> robots[i].y >> robots[i].d;
		for (int j = 0; j < 4; j++) {
			if (robots[i].d == dir[j]) {
				robots[i].dir = j;
				break;
			}
		}
	}
	
	for (int i = 1; i <= m; i++)
		cin >> orders[i].num >> orders[i].o >> orders[i].s;

	bool isOkay = true;
	for (int i = 1; i <= m; i++) {
		result situation = simulation(orders[i]);
		if (situation.errors != 0) {
			isOkay = false;
			if (situation.errors == 1) {
				cout << "Robot " << situation.who << " crashes into robot " << situation.whom << endl;
			}
			else {
				cout << "Robot " << situation.who << " crashes into the wall" << endl;
			}
			break;
		}
	}
	if (isOkay) {
		cout << "OK" << endl;
	}
	return 0;
}
