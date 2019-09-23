#include <iostream>
#include <cstring>
using namespace std;

int n, ans[13], tot;
bool map[2][100];

void solve(int * ans, int cur)
{
	if(cur == n)
	{
		tot++;
		if(tot < 4)
		{
			for(int i = 0; i < n; i++)
				cout << ans[i] << ' ';
			cout << endl;
		}
	}
	else
	{
		for(int i = 1; i <= n; i++)
		{
			if(!map[0][i] && !map[1][cur + i] && !map[2][cur - i + n])
			{
				if(tot < 4)
					ans[cur] = i;
				map[0][i] = true;
				map[1][cur + i] = true;
				map[2][cur - i + n] = true;

				solve(ans, cur + 1);
				
				map[0][i] = false;
				map[1][cur + i] = false;
				map[2][cur - i + n] = false;
			}
		}
	}
}

int main()
{
	cin >> n;
	solve(ans, 0);
	cout << tot;
	
	return 0;
}
