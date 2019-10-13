#include <iostream>
#include <algorithm>
using namespace std;

int n, ans, multi = 1;

struct Peo
{
    int left;
    int right;

    bool operator<(const Peo & a) const
    {
        return multi / right < multi / a.right;
    }

    friend istream & operator>>(istream &is, Peo &a)
    {
        is >> a.left >> a.right;
        return is;
    }
};

Peo pes[1001];

void solve()
{
    multi *= pes[0].left;
    for(int i = 1; i <= n; i++)
    {
        sort(pes + i, pes + n);
        ans = max(ans, multi / pes[i].right);
        multi *= pes[i].left;
    }
//    for(int i = 1; i <= n; i++)
//        cout << pes[i].left << ' ' << pes[i].right << endl;
    cout << ans;
}

int main()
{
    Peo item;
    cin >> n;
    for(int i = 0; i < n + 1; i++)
        cin >> pes[i];

    solve();

    return 0;
}