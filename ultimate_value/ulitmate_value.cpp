//#pragma warning (disable : 4996)
//#include <iostream>
//
//using namespace std;
//
//unsigned long long int Answer;
//unsigned long long int Answer1;
//
//
//int main(int argc, char** argv)
//{
//	int T, test_case;
//	long long n;
//	long long k;
//	long long j;
//	long long th;
//
//	cin >> T;
//	for (test_case = 0; test_case < T; test_case++)
//	{
//
//		Answer = 0;
//		Answer1 = 0;
//		k = 2;
//		j = 1;
//		cin >> n;
//
//		while (n > k) {
//			n -= k;
//			k *= 2;
//			j++;
//		}
//
//		k = k >> 1;
//		th = k >> 1;
//
//		if (j <= 10) {
//			for (int i = 0; i < j; i++)
//			{
//				Answer *= 10;
//				if (k >= n) {
//					Answer += 4;
//					k = k - th;
//				}
//				else {
//					Answer += 7;
//					n = n - th;
//				}
//				th = th >> 1;
//			}
//
//			cout << "Case #" << test_case + 1 << endl;
//			cout << Answer << endl;
//		}
//		else {
//			j -= 10;
//			for (int i = 0; i < 10; i++)
//			{
//				Answer *= 10;
//				if (k >= n) {
//					Answer += 4;
//					k = k - th;
//				}
//				else {
//					Answer += 7;
//					n = n - th;
//				}
//				th = th >> 1;
//			}
//			for (int i = 0; i < j; i++)
//			{
//				Answer1 *= 10;
//				if (k >= n) {
//					Answer1 += 4;
//					k = k - th;
//				}
//				else {
//					Answer1 += 7;
//					n = n - th;
//				}
//				th = th >> 1;
//			}
//
//
//
//			cout << "Case #" << test_case + 1 << endl;
//			cout << Answer << Answer1 << endl;
//		}
//
//	}
//
//	return 0;
//}