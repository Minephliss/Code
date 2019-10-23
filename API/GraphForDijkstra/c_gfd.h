#include <iostream>
#include <vector>
using namespace std;

#ifndef GFD_
#define GFD_

const int size = 10;

struct Node {
    int to;
    int dis;
    Node(int a = 0, int b = 0)
    {
        to = a;
        dis = b;
    }
    bool operator<(const Node& a) const
    {
        return dis < a.dis;
    }
};

class GFD {
private:
    int E;
    int V;
    vector<Node> adj[size];

public:
    GFD();
    ~GFD() {}
    int rE() { return E; }
    int rV() { return V; }
    vector<Node>* radj() { return adj; }
};

class Dijkstra {
private:
    int s, e;
    GFD graph;
    int* edgeto;

public:
    Dijkstra() {}
    Dijkstra(GFD& g);
    void init();
    friend ostream& operator<<(ostream& os, Dijkstra& dij);
};

#endif
