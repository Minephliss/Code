#include "c_dgraph.h"

DiGraph::DiGraph(istream& is)
{
    int v, w;
    is >> V >> E;
    for (int i = 0; i < E; i++) {
        is >> v >> w;
        addEdge(v, w);
    }
}

DiGraph::DiGraph(const int& v, const int& e)
{
    V = v;
    E = e;
}

void DiGraph::print(ostream& os) const
{
    using std::endl;
    os << "The V is: " << V << endl;
    os << "The E is: " << E << endl;
    for (int v = 0; v < V; v++) {
        os << v << ": ";
        for (int w = 0; w < adj[v].size(); w++)
            os << adj[v][w] << ' ';
        os << endl;
    }
    os << "Done!" << endl;
}

DiGraph DiGraph::reverse() const
{
    DiGraph temp(V, E);
    for (int i = 0; i < V; i++)
        for (int j = 0; j < adj[i].size(); j++)
            temp.addEdge(adj[i][j], i);
    return temp;
}
//DiGraph::DiGraph(const DiGraph& G)
//{}
//===============================================
Search::Search(const DiGraph& G, const int& s)
{
    marked = new bool[G.rV()];
    edgeTo = new int[G.rE()];
    this->s = s;
    dfs(G, s);
}

Search::~Search()
{
    delete[] marked;
    delete[] edgeTo;
}

void Search::printPath(const int& v, ostream& os) const
{
    if (!marked[v]) {
        os << "No path\n";
        return;
    }
    os << "Path " << s << " to " << v << " is:";
    int stack[size];
    int top = 0;
    stack[top++] = v;
    for (int w = edgeTo[v]; w != s; w = edgeTo[w])
        stack[top++] = w;
    stack[top++] = s;
    while (top > 0)
        os << stack[--top] << ' ';
    os << std::endl;
}

void Search::dfs(const DiGraph& G, const int& v) const
{
    marked[v] = true;
    vector<int> node = G.radj(v);
    for (int w = 0; w < node.size(); w++)
        if (!marked[node[w]]) {
            edgeTo[node[w]] = v;
            dfs(G, node[w]);
        }
}
//===============================================
DirectedCycle::DirectedCycle(const DiGraph& G)
{
    edgeTo = new int[G.rV()];
    marked = new bool[G.rV()];
    cycles = new vector<int>[size];
    dfs(G, 0);
}

DirectedCycle::~DirectedCycle()
{
    delete[] edgeTo;
    delete[] marked;
    delete[] cycles;
}

void DirectedCycle::print(ostream& os) const
{
    os << "Here are " << count << " cycles\n";
    for (int i = 0; i < count; i++) {
        os << "Cycle " << i << ':';
        for (int j = 0; j < cycles[i].size(); j++)
            os << cycles[i][j] << ' ';
        os << std::endl;
    }
    os << "Done!" << std::endl;
}

void DirectedCycle::dfs(const DiGraph& G, const int& v) const
{
    marked[v] = true;
    vector<int> node = G.radj(v);
    for (int w = 0; w < node.size(); w++) {
        if (!marked) {
            edgeTo[node[w]] = v;
            dfs(G, v);
        } else {
        }
    }
}
//===============================================
SCC::SCC(const DiGraph& G)
{
    marked = new bool[G.rV()];
    id = new int[G.rV()];
    arr = new int[G.rV()];
    top = 0;
    count = 0;
    mode = true;
    for (int v = 0; v < G.rV(); v++)
        if (!marked[v])
            dfs(G, v);
    mode = false;
    delete[] marked;
    marked = new bool[G.rV()];
    while (top > 0)
        if (!marked[arr[--top]]) {
            dfs(G, arr[top]);
            count++;
        }
}

void SCC::dfs(const DiGraph& G, const int& v)
{
    marked[v] = true;
    vector<int> node = G.radj(v);
    for (int w = 0; w < node.size(); w++)
        if (!marked[node[w]])
            dfs(G, node[w]);
    if (mode)
        arr[top++] = node[v];
    else
        id[v] = count;
}

void SCC::print(ostream& os, const DiGraph& G, const int& num) const
{
    os << "SCC num " << num << " is:";
    for (int v = 0; v < G.rV(); v++)
        if (id[v] == num)
            os << v << ' ';
    os << std::endl;
}

void SCC::print(ostream& os, const DiGraph& G) const
{
    os << "All SCC:\n";
    for (int i = 0; i < count; i++) {
        os << "SCC num " << i << " is:";
        for (int v = 0; v < G.rV(); v++) {
            if (id[v] == i)
                os << v << ' ';
            os << std::endl;
        }
    }
}
