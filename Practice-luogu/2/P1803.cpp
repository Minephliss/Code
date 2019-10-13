#include <iostream>
#include <queue>
using namespace std;

struct Contest
{
    int begin;
    int end;
    bool operator>(const Contest & a) const
    {
        return end > a.end;
    }
    friend istream & operator>>(istream & is, Contest & item)
    {
        return is >> item.begin >> item.end;
    }
};

priority_queue<Contest, vector<Contest>, greater<Contest> > cts;
int n, ans;

void solve()
{
    int now = 0;
    while(!cts.empty())
    {
        if(cts.top().begin >= now)
        {
            now = cts.top().end;
            ans++;
        }
        cts.pop();
    }
    cout << ans;
}

int main()
{
    Contest item;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> item;
        cts.push(item);
    }

    solve();

    return 0;
}