

#include <iostream>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	int table[4];
	char str[10001];

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{

		Answer = 0x7fffffff;
		cin >> str;
		
		for (int i = 0; i < 4; i++)
			table[i] = 0;


		for (char c : str)
		{
			if (c == '\0')
				break;

			switch (c)
			{
			case 'h':
				table[0]++;
				break;
			case 'e':
				table[1]++;
				break;
			case 'o':
				table[2]++;
				break;
			case 'l':
				table[3]++;
				break;
			}
		}



		for (int i = 0; i < 3; i++)
		{
			if (Answer > table[i])
				Answer = table[i];
		}
		table[3] >>= 1;
		if (Answer > table[3])
			Answer = table[3];




		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}