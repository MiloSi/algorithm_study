#include <iostream>
using namespace std;
struct stack {
	int black;
	int gray;
	int white;
};


void input(stack *s, int v, int number) {
	if (number == 0)
		s->black = v;
	else if(number == 1)
		s->gray = v;
	else
		s->white = v;
}
int cal(stack *s, int v) {
	if ((s)->black >= v) {
		(s)->black--;
		return 1;
	}
	else {
		v -= (s)->black;
	}
	if ((s)->gray >= v) {
		(s)->gray--;
		return 2;
	}
	else {
		v -= (s)->gray;
	}
	if ((s)->white >= v) {
		(s)->white--;
		return 5;
	}
	
	return 0;

}



int main() {

	int n, v;
	int m, r;
	int sum;
	struct stack* s;

	cin >> n;

	s = new stack[n];

	for(int k = 0; k < 3; k++)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> v;
			input(&s[i], v, k);
		}
	}
	cin >> m;

	for (int k = 0; k < m; k++)
	{
		cin >> r;

		sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += cal(&s[i], r);
		}
		
		cout << sum << endl;
	}
	delete[] s;
	
	return 0;
}