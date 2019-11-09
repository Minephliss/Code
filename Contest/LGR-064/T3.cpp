#include <iostream>
using namespace std;

struct link
{
    int ch;
    link* next;
};

int n, m;
int ch[100000];
int opt[100000];
int S[110000];
int Tsize;

link* T;
link* Tend;

void read()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> S[i];
    for(int i = 0; i < m; i++)
        cin >> opt[i] >> ch[i];
}

int Tsearch(int at)
{
    at--;
    link* cur = T;
    while(at--)
        cur = cur->next;
    return cur->ch;
}

void judge()
{
    int cnt = 0;
    bool ok;
    for(int l = 1; l <= Tsize; l++)
    {
        ok = true;
        for(int i = 1; i <= l; i++)
        {
            if(Tsearch(Tsize - l + i) == S[i])
            {
                ok = false;
                break;
            }
        }
        if(ok)  cnt++;
    }
    cout << cnt << endl;
}

void addF(int tar)
{
    link* cur;
    cur = new link;
    cur->next = T;
    cur->ch = tar;
    T = cur;
}

void addB(int tar)
{
    link* cur;
    cur = new link;
    cur -> ch = -1;
    cur -> next = nullptr;
    Tend -> ch = tar;
    Tend ->next = cur;
    Tend = cur;
}

void solve()
{
    T = new link;
    Tend = new link;
    Tend->next = nullptr;
    Tend->ch = -1;
    T->next = Tend;
    T->ch = ch[0];
    Tsize++;
    judge();

    for(int t = 1; t < m; t++)
    {
        Tsize++;
        if(opt[t])
        {
            addF(ch[t]);
        }
        else
        {
            addB(ch[t]);
        }
        judge();
    }
}

int main()
{
//    read();
//    solve();
    T = new link;
    Tend = new link;
    Tend->next = nullptr;
    Tend->ch = -1;
    T->next = Tend;
    T->ch = 1;
    Tsize++;
    for(int i = 1; i <= 10; i++)
    {
        addF(i);
        Tsize++;
    }
    addB(11);
    Tsize++;
    for(int i = 1; i <= Tsize; i++)
    {
        cout << Tsearch(i) << ' ';
    }
    return 0;
}