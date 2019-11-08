#include <iostream>
#include <queue>
using namespace std;

const int maxn = 10010;

int n, m;
vector<int> graph[maxn];

void read()
{

    int a, b;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
}

bool bfs(int s,int& a, bool * marked, bool * binarygraph)
{
    int cnt = 0, res = 0;
    queue<int> que;
    marked[s] = true;
    que.push(s);
    while(!que.empty())
    {
        cnt++;
        int v = que.front();  que.pop();
        if(binarygraph[v])  res++; 
        for(int i = 0; i < graph[v].size();i++)
        {
            int w = graph[v][i];
            if(!marked[w])
            {
                binarygraph[w] = !binarygraph[v];
                marked[w] = true;
                que.push(w);
            }
            else
                if(binarygraph[w] == binarygraph[v])
                {
                    cout << "Impossible";
                    return false;
                }
        }
    }
    a = a + min(res, cnt - res);
    return true;
}

void solve()
{
    int res = 0;
    bool marked[maxn];
    bool binarygraph[maxn];
    int cnt = n;
    for(int i = 0; i < n; i++)
        binarygraph[i] = marked[i] = false;
    for(int i = 0; i < n; i++)
        if(!marked[i])
        {
            if(graph[i].size() == 0)
            {
                marked[i] = true;
                cnt--;
            }
            else if(!bfs(i, res, marked, binarygraph))
                return;
        }
    res = min(res, cnt - res);
    cout << res;
}

int main()
{
    read();
    solve();
    return 0;
}
