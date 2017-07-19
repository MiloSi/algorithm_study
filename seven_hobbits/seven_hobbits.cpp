#include <iostream>
#include <algorithm>
using namespace std;


bool sum(int c,int d, int* hobbits){
	int a =0;
	for (int i = 0; i < 9; i++)
	{
		if (i == c || d == i) continue;
		a += hobbits[i];
	}
	if (a == 100) return true;
	return false;

}


int main() {

	int hobbits[9];
	int c, d;
	bool a = false;
	for (int i = 0; i < 9; i++)
		cin >> hobbits[i];
	sort(hobbits, hobbits + 9);


	cout << endl;
	for (c = 0; c < 8; c++)
	{
		for (d = c + 1; d < 9; d++)
		{
			a = sum(c, d, hobbits);
			if (a)
				break;
		}
		if (a)
			break;
	}
	for (int i = 0; i < 9; i++)
	{
		if (c == i || d == i) continue;
			cout << hobbits[i] << endl;
	}






	return 0;

}