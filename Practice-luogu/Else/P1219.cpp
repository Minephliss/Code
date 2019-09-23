#include <iostream>
#include <cstring>
using namespace std;

int n, ans[13];

void solve(int * ans, int cur)
{
	if(cur == n)
	{
		for(int i = 0; i < n; i++)
			cout << ans[i] << ' ';
		cout << endl;
	}
	else
	{
		for(int i = 1; i <= n; i++)
		{
			bool ok = true;
			for(int c = 0; c < cur; c++)
				if(ans[c] == i || abs(ans[c] - i) == abs(c - cur))
					ok = false;
			if(ok)
			{
				ans[cur] = i;
				solve(ans, cur + 1);
			}
		}
	}
}

int main()
{
	cin >> n;
	solve(ans, 0);
}
