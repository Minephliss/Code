#include <iostream>
using namespace std;

int n, v, m;
int V[50];
int M[50];
int val[50];
int dp[50][400][400];

void solve()
{
    for(int j = 0; j <= v; j++)
        for(int k = 0; k <= m; k++)
            dp[0][j][k] = 0;

    for(int i = 0; i < n; i++)
        for(int j = 0; j <= v; j++)
            for(int k = 0; k <= m; k++)
            {
                if(j - V[i + 1] >= 0 && k- M[i + 1] >= 0)
                    dp[i + 1][j][k] = max(dp[i][j][k], dp[i][j - V[i + 1]][k - M[i + 1]] + val[i + 1]);
                else
                    dp[i + 1][j][k] = dp[i][j][k];
            }
    
    cout << dp[n][v][m];
}

void read()
{
    cin >> v >> m >> n;
    for(int i = 0; i < n; i++)
        cin >> V[i] >> M[i] >> val[i];
}

int main()
{
    read();
    solve();
    return 0;
}
