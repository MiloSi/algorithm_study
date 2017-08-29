#pragma warning(disable:4996)
#include <cstdio>
#include <cstdlib>
char input[51];
char output[51];
int dna[51][4]; // A T G C
int frequency;
int n, m, _Min = 0, idx = 0;
char _Case[4] = { 'A','C','G','T' };
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %c", input + j);
			switch (input[j])
			{
			case 'A':
				dna[j][0]++;
				break;			
			case'C':
				dna[j][1]++;
				break; 
			case 'G':
				dna[j][2]++;
				break;
			case 'T':
				dna[j][3]++;
				break;
			}
		}
		fflush(stdin);
	}
	for (int i = 0; i < m; i++) {
		frequency = dna[i][0];
		idx = 0;
		for (int j = 1; j < 4; j++) {
			if (frequency < dna[i][j]) {
				frequency = dna[i][j];
				idx = j;
			}
		}
		_Min += (n - frequency);
		output[i] = _Case[idx];
	}
	puts(output);
	printf("%d\n", _Min);
	system("pause");
	return 0;
}