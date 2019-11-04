#include <iostream>
using namespace std;

int dp[25][30001];
int money[25];
int value[25];

int n, m;

void solve()
{
	for (int i = 0; i <= n; i++)
		dp[0][n] = 0;
    for (int i = 1; i <= m; i++)
        for (int j = 0; j <= n; j++)
			if(j >= money[i])
				dp[i][j] = max(dp[i - 1][j - money[i]] + money[i] * value[i], dp[i - 1][j]);
			else dp[i][j] = dp[i - 1][j];
    cout << dp[m][n];
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> money[i] >> value[i];
    solve();
    return 0;
}
