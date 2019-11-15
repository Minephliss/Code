#include <iostream>
using namespace std;

int m, n;
int dp[31][20001];
int its[31];

void read()
{
    cin >> m >> n;
    for (int i = 0; i < n; ++i)
        cin >> its[i];
}

void solve1()
{
    read();
    for (int i = 0; i <= m; ++i)
        dp[0][i] = m;

    for (int i = 0; i < n; ++i) {
        for (int j = m; j >= 0; j--) {
            if (dp[i][j + its[i]]>=its[i] && j + its[i] <= m)
                dp[i + 1][j] = min(dp[i][j + its[i]] - its[i], dp[i][j]);
            else
                dp[i + 1][j] = dp[i][j];
        }
    }

    cout << dp[n][0];
}

void solve2()
{
    read();
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if(dp[i][j - its[i]] + its[i]<=m && j > its[i])
                dp[i+1][j]=max(dp[i][j - its[i]] + its[i], dp[i][j]);
            else
                dp[i+1][j]=dp[i][j];
        }
    }
    cout << m - dp[n][m];
}

int main()
{
    solve2();
    return 0;
}
