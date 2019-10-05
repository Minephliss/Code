#include <iostream>
using namespace std;

int N, M, sum = 1;

int main()
{
	int x;
	cin >> N >> M;
	for(int i = 0, temp = 0; i < N; i++)
	{
		cin >> x;
		if(temp + x <= M)
			temp += x;
		else
		{
			sum++;
			temp = x;
		}
	}
	cout << sum;
	return 0;
}
