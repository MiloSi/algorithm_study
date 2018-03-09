#include <iostream>
using namespace std;

const int TEST_MAX = 10;
const int ROWS_MAX = 8;
const int COLS_MAX = 8;
char cArray[8][9];

//Init Input Array
void inputArray() {
	for (int i = 0; i < ROWS_MAX; i++) {
		cin >> cArray[i];
	}
}
int checkRowPalindrome(const int y, const int x, int searchVal) {
	int toX = x + searchVal - 1;
	int fromX = x;
	while (fromX < toX) {
		if (cArray[y][fromX] != cArray[y][toX]) {
			return 0;
		}
		++fromX;
		--toX;
	}
	return 1;
}
int checkColPalindrome(const int y, const int x, int searchVal) {
	int toY = y + searchVal - 1;
	int fromY = y;

	while (fromY < toY) {
		if (cArray[fromY][x] != cArray[toY][x]) {
			return 0;
		}
		++fromY;
		--toY;
	}
	return 1;
}
// Using brute force
int solution(const int& searchVal) {
	int retval = 0;
	int range = searchVal- 1;

	for (int y = 0; y < ROWS_MAX; y++) {
		for (int x = 0; x < COLS_MAX; x++) {
			if (y + range < ROWS_MAX) {
				retval += checkColPalindrome(y, x, searchVal);
			}
			if (x + range < COLS_MAX) {
				retval += checkRowPalindrome(y, x, searchVal);
			}
		}
	}
	return retval;
}

int main() {
	int searchVal;
	for (int t = 1; t <= TEST_MAX; t++) {
		cin >> searchVal;
		inputArray();
		cout << "#" << t << " " << solution(searchVal) << endl;
	}
	return 0;
}
