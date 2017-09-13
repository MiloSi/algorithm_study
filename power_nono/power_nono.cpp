#pragma warning(disable : 4996)
#include <cstdio>
#include<vector>
using namespace std;
bool check[1000001]; 
int main()
{
	vector<long long int> v;
	long long int _min, _max;
	scanf("%lld %lld", &_min, &_max);
	for (long long int i = 2;; i++)
	{
		if (i*i > _max) break;
		v.push_back(i*i);
	}
	long long int answer = 0;
	int size = v.size();
	for (int i = 0; i < size; i++)
	{
		for (long long int j = (_min / v[i])*v[i]; j <= _max; j += v[i])
		{
			if (j - _min < 0) continue;
			if (check[j - _min] == 0)
			{
				check[j - _min] = 1;
				answer++;
			}
		}
	}
	printf("%lld\n", _max - _min - answer + 1);
	return 0;
}