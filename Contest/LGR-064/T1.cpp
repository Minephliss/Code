#include <iostream>
using namespace std;

long long n, k, tot;
long long ai[201000];
long long ki[101000];

void read()
{
    cin >> n >> k;
    for(int i = 0; i < n - 1; i++)
    {
        cin >> ai[i];
        tot += ai[i];
    }
}

void solve()
{
    if(k >= n - 1)
    {
        cout << 0;
        return;
    };
    if(k == 0)
    {
        cout << tot;
        return;
    }
    long long por = 0;
    long long val = 0;
    for(int i = 0; i < k; i++)
    {
        val += ai[i];
        por = val;
    }

    for(int i = 0; i < n - k; i++)
    {
        val += ai[i + k] - ai[i];
        por = max(val, por);
    }
    cout << tot - por;
}

int main()
{
    read();
    solve();
    return 0;
}