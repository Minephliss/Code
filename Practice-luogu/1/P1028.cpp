#include <iostream>

using namespace std;

int cnt;
int mem[1010];

void loop(int num)
{
	int temp = cnt;
	
	if(mem[num] != 0)
	{
		cnt += mem[num];
		return;
	}

	if(num > 0)
	{
		for(int i = 1; i <= num / 2; i++)
			loop(i);
		cnt++;
	}

	if(mem[num] == 0)
		mem[num] = cnt - temp;
}

int main()
{
	int n;
	cin >> n;
	loop(n);
	cout << cnt;

	return 0;
}
