#include <iostream>
#include <vector>
using namespace std;

#ifndef C_dgraph
#define c_dgraph

const int size = 50;

class DiGraph {
private:
    int V;
    int E;
    vector<int> adj[size];

public:
    DiGraph(istream& is);
    DiGraph(const int& v, const int& e);
    DiGraph()
    {
        E = 0;
        V = 0;
    }
    //    DiGraph(const DiGraph& G);
    int rV() const { return V; }
    int rE() const { return E; }
    vector<int> radj(const int& v) const { return adj[v]; }
    void addEdge(const int& v, const int& w) { adj[v].push_back(w); }
    void print(ostream& os) const;
    DiGraph reverse() const;
};

class Search {
private:
    bool* marked;
    int* edgeTo;
    int s;

public:
    Search(const DiGraph& G, const int& s);
    ~Search();
    bool havePathTo(const int& v) const;
    void printPath(const int& v, ostream& os) const;
    void dfs(const DiGraph& G, const int& v) const;
};

class DirectedCycle {
private:
    int* edgeTo;
    vector<int>* cycles;
    bool* marked;
    int count;

public:
    DirectedCycle(const DiGraph& G);
    ~DirectedCycle();
    bool hasCycle() const;
    void print(ostream& os) const;
    void dfs(const DiGraph& G, const int& v) const;
};

class SCC {
private:
    bool* marked;
    bool mode;
    int count;
    int* id;
    int top;
    int* arr;

public:
    SCC(const DiGraph& G);
    int howMany() const { return count; }
    void dfs(const DiGraph& G, const int& v);
    void print(ostream& os, const DiGraph& G, const int& num) const;
    void print(ostream& os, const DiGraph& G) const;
};
#endif
