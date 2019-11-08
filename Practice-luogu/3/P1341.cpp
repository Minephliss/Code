#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

int ola, n;
bool cnt[52];
int instk[52][52];
int st[2];
queue<int> que;
priority_queue<int, vector<int>, greater<int> > prque;
vector<int> graph[52];

int CtoN(char c)
{
    if(c <= 'Z')
        return (int)(c - 'A');
    else
        return (int)(c - 'A' - 6);
}

char NtoC(int n)
{
    if(n < 26)
        return (char)(n + 'A');
    else
        return (char)(n + 'A' + 6);
}

bool read(){
    cin >> n;
    string p;
    for(int i = 0; i < 52; i++)
        cnt[i] = false;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> p;
        a = CtoN(p[0]);
        b = CtoN(p[1]);
        if(a == b)
        {
            graph[a].push_back(b);
            prque.push(a);
        }
        else
        {
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        cnt[a] = cnt[b] = true;
    }
    for(int i = 0; i < 52; i++)
        if(cnt[i])
        {
            if(graph[i].size() % 2 != 0)
            {
                if(prque.top() == i)
                    prque.pop();
                else
                    st[ola++] = i;
            }
            sort(graph[i].begin(), graph[i].end());
        }
    if(ola == 2 || ola == 0)
        return true;
    else
    {
        cout << "No Solution";
        return false;
    }
}

void dfs(int s){
    que.push(s);
    for (int i = 0; i < graph[s].size(); i++){
        int w = graph[s][i];
        if(!instk[s][w])
        {
            instk[s][w] = instk[w][s] = true;
            dfs(w);
        }
    }
}

void solve(){
    for(int i = 0; i < 52; i++)
        if(cnt[i]){
            if(ola == 2)
                dfs(st[0]);
            else if(ola == 0)
                dfs(i);
            while(!que.empty())
            {
                cout << NtoC(que.front());
                que.pop();
            }
            break;
        }
}

int main()
{
    if(read())
        solve();
    return 0;
}