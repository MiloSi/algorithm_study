#include <iostream>
#include <algorithm>

#define MAX 5005

using namespace std;

int heap[MAX];


void insert(int c, int n) {
	for (int j = c; j > 1; j /= 2) {
		if (heap[j] > heap[j / 2]) {
			swap(heap[j], heap[j / 2]);
		}
	}
}


void heapSort(int n) {
	for (int i = 1; i <= n; i++) {

		swap(heap[1], heap[n - i + 1]);

		for (int j = 1; ; ) {

			int k = j * 2;

			if (k > n - i) break;

			if (k + 1 <= n - i && heap[k] < heap[k + 1]) k++;

			if (heap[j] < heap[k]) {
				swap(heap[j], heap[k]);
				j = k;
			}

			else break;
		}

	}

}



int main()
{
	int n;

	cin >> n;

	
	for (int i = 1; i <= n; i++) {
	
		cin >> heap[i];
		insert(i, n);
	}

	heapSort(n);

	for (int i = 1; i <= n; i++)

		cout << heap[i] << " ";
	cout << endl;

	return 0;
}
