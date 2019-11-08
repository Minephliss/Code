#include <iostream>
#include <queue>
#include <string>
#include <map>
using namespace std;

struct Node
{
    int to;
    bool ok;
    Node() {    }
    Node(int a, bool b) {to = a; ok = b;}
};

struct Edge
{
    int x;
    int y;
    Edge() {    }
    Edge(int a, bool b) {x = a; y = b;}
};

vector<Node> graph[30000];
int n, k;
map<long long, int> mem;

void read()
{
    cin >> n >> k;
    for(int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[--a].push_back(Node(--b, true));
        graph[b].push_back(Node(a, true));
    }
}

void dfs(int s, int y, bool* marked, int& res)
{
    res++;
    marked[s] = true;
    marked[y] = true;
    for(int i = 0; i < graph[s].size();i++)
    {
        int w = graph[s][i].to;
        if(!marked[w])
            dfs(w, y, marked, res);
    }
}

int val(int x, int y)
{
    if(mem.count(x * y + x + y))
        return mem[x * y + x + y];
    bool marked[30001];
    for(int i = 0; i < n; i++)
        marked[i] = false;
    int a = 0;
    dfs(x, y, marked, a);
    for(int i = 0; i < n; i++)
        marked[i] = false;
    int b = 0;
    dfs(y, x, marked, b);
    return mem[x * y + x + y] = a * b;
}

void bfs(int s, int& re)
{
    queue<int> que;
    int value[30001];
    int mark[30001];
    
    for(int i = 0; i < n; i++)
    {
        value[i] = 0;
        mark[i] = false;
    }

    que.push(s);
    mark[s] = true;
    while(!que.empty())
    {
        int v = que.front();    que.pop();
        if(value[v] > k)
            break;
        for(int i = 0; i < graph[v].size();i++)
        {
            Node w = graph[v][i];
            if(!mark[w.to])
            {
                value[w.to] = value[v] + 1;
                re = re + val(v, w.to);
                que.push(w.to);
                mark[w.to] = true;
            }
        }
    }
}

void solve()
{
    int res = 0;
    for(int i = 0; i < n; i++)
    {
        vector<Edge> r;
        int re = 0;
        bfs(i, re);
        res = max(re, res);
    }
    cout << res;
}

int main()
{
    read();
    solve();
    return 0;
}