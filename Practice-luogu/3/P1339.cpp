#include <iostream>
#include <queue>
#define inf __INT_MAX__
using namespace std;

struct Node 
{
    int to;
    int dis;
    Node () { }
    Node (int a, int b) {to = a; dis = b;}
    bool operator>(const Node& a ) const
    {
        return dis > a.dis;
    }
};

int n, m, start, destination;
vector<Node> adj[2500];
priority_queue<Node, vector<Node>, greater<Node> > prque;

void read()
{
    int a, b, c;
    cin >> n >> m >> start >> destination;    
    start--;
    destination--;
    while(m--)
    {
        cin >> a >> b >> c;
        adj[--a].push_back(Node(--b, c));
        adj[b].push_back(Node(a, c));
    }
}

int dijkstra()
{
    int dis[2500];
    for(int i = 0; i < n; i++)
        dis[i] = inf;
    dis[start] = 0;
    prque.push(Node(start, 0));
    while(!prque.empty())
    {
        Node v = prque.top();    prque.pop();
        if(dis[v.to] != v.dis)  continue;
        for(int i = 0; i < adj[v.to].size(); i++)
        {
            Node w = adj[v.to][i];
            if(dis[w.to] > v.dis + w.dis)
            {
                dis[w.to] = v.dis + w.dis;
                prque.push(Node(w.to, dis[w.to]));
            }
        }
    }
    return dis[destination];
}

void solve()
{
    cout << dijkstra();
}

int main()
{
    read();
    solve();
    return 0;
}