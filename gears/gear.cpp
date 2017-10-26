#include <iostream>
using namespace std;
char gears[5][9];
void whiling(int who, int dir) {
	if (dir == 1) {
		char temp = gears[who][7];
		for (int i = 7; i > 0; i--)
			gears[who][i] = gears[who][i - 1];
		gears[who][0] = temp;
	}
	else {
		char temp = gears[who][0];
		for (int i = 0; i < 7; i++)
			gears[who][i] = gears[who][i + 1];
		gears[who][7] = temp;
	}
}
void left_propagation(int who, char ns, int dir) {
	if (who == 0) return;

	char co = gears[who][2];
	char to = gears[who][6];
	if (ns != co) {
		whiling(who, -dir);
		left_propagation(who - 1, to, -dir);
	}
}
void right_propagation(int who, char ns, int dir) {
	if (who == 5) return;
	char co = gears[who][6];
	char to = gears[who][2];

	if (ns != co) {
		whiling(who, -dir);
		right_propagation(who +1 , to, -dir);
	}
}
int main() {
	int k;
	int who, dir;

	for (int i = 1; i <= 4; i++) {
		cin >> gears[i];
	}
	cin >> k;
	char left, right;
	for (int i = 0; i < k; i++) {
		cin >> who >> dir;
		right = gears[who][2];
		left = gears[who][6];
		whiling(who, dir);
		left_propagation(who - 1, left, dir);
		right_propagation(who + 1, right, dir);
	}
	int ans = 0;
	for (int i = 1; i <= 4; i++) {
		if (gears[i][0] == '1') ans += (1 << (i - 1));
	}
	cout << ans << endl;
}
