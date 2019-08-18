#include <iostream>
#include <string>
#include <vector>
using namespace std;

#ifndef c_g
#define c_g

const int size = 50;
enum SearchMode { DFS = 0,
    BFS = 1 };

class Graph {
private:
    int V;
    int E;
    vector<int> adj[size];

public:
    //    Graph(const int& s);
    Graph(istream& is);
    Graph()
    {
        V = size;
        E = 0;
    }
    int rV() const { return V; }
    int rE() const { return E; }
    void addEdge(const int& v, const int& w)
    {
        if (v != w) {
            adj[v].push_back(w);
            adj[w].push_back(v);
            E++;
        } else
            adj[v].push_back(w);
    }
    vector<int> radj(const int& v) const;
    void print(ostream& os) const;
    int degree(const int& v) const;
    int maxDegree() const;
    int number0SelfLoops() const;
};
//============================================
class Search {
private:
    bool* marked;
    int* edgeTo;
    int s;
    SearchMode mode;

public:
    Search(const Graph& G, const int& s, const SearchMode& m);
    ~Search();
    void dfs(const Graph& G, int v) const;
    void bfs(const Graph& G) const;
    bool hasPathTo(const int& v) const
    {
        return marked[v];
    }
    void printPath(const int& v, ostream& os) const;
};
//=========================================
class CC {
private:
    int count;
    int* id;
    bool* marked;

public:
    CC(const Graph& G);
    ~CC();
    bool connected(const int& v, const int& w) const;
    int rcount() const;
    int rid(const int& v) const;
    void dfs(const Graph& G, int& v);
};

//===============================================
class Cycle {
private:
    bool* marked;
    bool cycle;
    int* edgeTo;

public:
    Cycle(const Graph& G);
    ~Cycle();
    bool rcycle() const { return cycle; };
    void dfs(const Graph& G, const int& v);
};

//===============================================
class TwoColor {
private:
    bool* marked;
    bool* colors;
    bool iscolor;

public:
    TwoColor(const Graph& G);
    ~TwoColor();
    void dfs(const Graph& G, const int& v);
    bool isColors() const { return iscolor; };
};
#endif
