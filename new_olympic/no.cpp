/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
#include<iostream>
using namespace std;
const int MAX_NUM = 1001;

int solution(const int& N, const int& M) {
	int* A = new int[N+1];
	int* B = new int[M+1];
	int* table = new int[MAX_NUM]();
	int maxIdx = 0;
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	for (int i = 1; i <= M; ++i) {
		cin >> B[i];
	}
	for (int bIdx = 1; bIdx <= M; ++bIdx) {
		for (int aIdx = 1; aIdx <= N; aIdx++) {
			if (A[aIdx] <= B[bIdx]) {	
				++table[aIdx];
				if (table[aIdx] > table[maxIdx]) {
					maxIdx = aIdx;
				}
				break;
			}
		}
	}
	delete[] A;
	delete[] B;
	delete[] table;
	return maxIdx;
}

int main(int argc, char** argv)
{
	int test_case;
	int T, N, M;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> M;
		cout << "#" << test_case << " " << solution(N, M) << endl;

	}
	return 0;
}
