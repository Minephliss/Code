#include "c_gfd.h"
#include <queue>

GFD::GFD()
{
    cin >> V >> E;
    int v, w, d;
    for (int i = 0; i < E; i++) {
        cin >> v >> w >> d;
        adj[v].push_back(Node(w, d));
    }
}

Dijkstra::Dijkstra(GFD& g)
{
    cin >> s >> e;
    edgeto = new int[g.rV()];
    int d[size] = { __INT_MAX__ };
    priority_queue<Node> que;

    d[s] = 0;
    que.push(Node(s, 0));

    while (!que.empty()) {
        Node v = que.top();
        que.pop();
        for (unsigned i = 0; i < g.radj()[v.to].size(); i++) {
            Node w = g.radj()[v.to][i];
            que.push(Node(w.to, )) if (d[w.to] > d[v.to] + w.dis)
            {
                d[w.to] = d[v.to] + w.dis;
            }
        }
    }
}
