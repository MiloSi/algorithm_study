#include<iostream>
using namespace std;
char *result[2] = { "Alice", "Bob" };
int solution() {
	long long N; //1 <= N <= 10^18;
	cin >> N;
	int turn = 1;
	long long value = 1;
	long long k = 4;
	while (value < N) {
		value += k;
		turn = (turn + 1) % 2;
		if (turn == 1) {
			k *= 4;
		}
	}

	return turn;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int target = solution();
		cout << "#" << test_case << " " << result[target] << endl;
	}
	return 0;
}
