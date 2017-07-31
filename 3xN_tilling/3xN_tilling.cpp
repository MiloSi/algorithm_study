//#include <iostream>
//
//long long table[31];
//int main() {
//	int n;	
//	table[0] = 1;
//	table[1] = 0;
//	table[2] = 3;
//
//	std::cin >> n;
//
//	for (int i = 4; i <= n; i += 2)
//	{
//		table[i] = table[i - 2] * 3;
//		for (int j = 4; j <= i; j += 2) {
//			table[i] += table[i - j] * 2;
//		}
//	}
//
//	std::cout << table[n] << std::endl;
//
//	return 0;
//}