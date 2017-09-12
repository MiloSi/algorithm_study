//#include <iostream>
//#include <algorithm>
//#include <queue>
//// Macro
//#define LOP(i, j)  for(int i = 0;  i < j; i++)
//#define INPUT_N  "Input size of Pancakes. (betweeen 1 ~ 30)"
//#define INPUT_M  "Input pancakes. (between 1~10)"
//#define ERROR_N  "ERROR : out of size. "
//#define ERROR_M  "ERROR : out of pancake size . "
//using namespace std;
//int pancakes[31];
//int output[31];
//queue<int> flips_orders;
//bool checked(int& n, int* arr) {
//	LOP(i, n - 1) {
//		if (arr[i] > arr[i + 1]) return false;
//	}
//	return true;
//}
//bool show_result(int n) {
//	cout << "Output" << endl;
//	LOP(i, n) 	cout << pancakes[i] << " ";
//	cout << endl << 0 << endl;
//	return 0;
//}
//int searchMaxValue(int range) {
//	int maxValue = 0;
//	int idx = 0;
//	for (int i = 0; i < range; i++) {
//		if (output[i] >= maxValue) {
//			maxValue = output[i];
//			idx = i;
//		}
//	}
//	return idx;
//}
//void flip(int idx) { 
//	//#inlcude<algorithm> std::reverse
//	reverse(output, output + idx + 1);
//}
//int main() {
//	int n; // n = size of pancakes
//	cout << INPUT_N << endl;
//
//	cin >> n; // input size of pancakes;
//	//defensive code
//	if (n > 30 || n < 1) {
//		cerr << ERROR_N << endl;
//		return 0;
//	}
//	cout << INPUT_M << endl;
//	LOP(i, n) {
//		cin >> pancakes[i];
//		if (1 > pancakes[i] || pancakes[i] > 10) {
//			cerr << ERROR_M << endl;
//			return 0;
//		}
//	}
//	// if pancakes are already sorted, show.
//	if (n >= 1) {
//		if (n == 1) {
//			show_result(n);
//		} 
//		else if (checked(n, pancakes)) {
//			show_result(n);
//			return 0;
//		}
//	}
//	//copy
//	LOP(i, n) output[i] = pancakes[i];
//	//flips
//	int range = n;
//	while (range) {
//		int idx = searchMaxValue(range);
//		if (idx != range - 1) {
//			if (idx) {
//				flip(idx);
//				flips_orders.push(n - idx);
//			}
//			flip(--range);
//			flips_orders.push(n - range);
//			if (checked(n, output)) break;
//		}
//		else range--;
//	}
//
//	cout << "Output" << endl;
//
//	LOP(i, n) 	cout << pancakes[i] << " ";
//	cout << "(";
//	LOP(i, n) cout << output[i] << " ";
//	cout << ")" << endl;
//
//	while (flips_orders.size()) {
//		cout << flips_orders.front() << " ";
//		flips_orders.pop();
//	}
//	cout << 0 << endl;
//	return 0;
//}