//#include <iostream>
//#include <math.h>
//
//using namespace std;
//int square[330];
//int sequence[100001] = { 0, };
//
//inline int MIN(int a, int b) {
//
//	return a < b ? a : b;
//}
//
//int main() {
//	int n;
//	cin >> n;
//
//	int t = sqrt(n);
//
//	for (int i = 1; i <= t; i++)
//		square[i] = i*i;
//
//
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= t; j++)
//		{
//			if (square[j] <= i) {
//				if (sequence[i] == 0) {
//					sequence[i] = sequence[i - square[j]] + 1;
//				}
//				else {
//					sequence[i] = MIN(sequence[i], sequence[i - square[j]] + 1);
//				}
//			}
//			else
//				break;
//		}
//	}
//	cout << sequence[n] << endl;
//
//	return 0;
//
//}
