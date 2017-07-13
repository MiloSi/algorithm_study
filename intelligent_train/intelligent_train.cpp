#include <iostream>

using namespace std;

int main() {
	int total = 0;
	int in, out;
	int max = 0;


	for (int i = 0; i < 4; i++)
	{
		cin >> out >> in;
		total += in - out;
		if (total > max)
			max = total;
	}
	cout << max << endl;


}