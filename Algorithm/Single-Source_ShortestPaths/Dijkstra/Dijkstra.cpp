#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int to;
    int d;
    Node(int a, int b)
        : to(a)
        , d(b)
    {
    }
    bool operator>(const Node& a) const { return d > a.d; }
};

int* dis;
int start, Vmount, Nmount;
vector<Node>* map;

void init()
{
    for (int i = 0; i < Vmount; i++)
        dis[i] = __INT_MAX__;
}

void dijkstra(int start)
{
    init();
    dis[start] = 0;
    priority_queue<Node, vector<Node>, greater<Node>> que;
    que.push(Node(start, dis[start]));
    while (!que.empty()) {
        Node v = que.top();
        que.pop();
        if (dis[v.to] != v.d)
            continue;
        for (unsigned i = 0; i < map[v.to].size(); i++) {
            Node w = map[v.to][i];
            if (dis[w.to] > w.d + v.d) {
                dis[w.to] = w.d + v.d;
                que.push(Node(w.to, dis[w.to]));
            }
        }
    }
}

void read()
{
    int a, b, c;
    cin >> Vmount >> Nmount >> start;
	start--;
    dis = new int[Vmount];
    map = new vector<Node>[Vmount];
    for (int i = 0; i < Nmount; i++) {
        cin >> a >> b >> c;
        map[a - 1].push_back(Node(b - 1, c));
    }
}

int main()
{
    read();
    dijkstra(start);
    for (int i = 0; i < Vmount; i++)
        cout << dis[i] << ' ';

    return 0;
}
