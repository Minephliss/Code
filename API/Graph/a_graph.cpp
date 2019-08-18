#include "c_graph.h"
#include <queue>

/*Graph::Graph(const int& s)
    : size(s)
{
    V = size;
    E = 0;
}*/

Graph::Graph(istream& is)
{
    int Ed;
    is >> V >> Ed;

    for (int i = 0; i < Ed; i++) {
        int v;
        int w;
        is >> v >> w;
        addEdge(v, w);
    }
}
vector<int> Graph::radj(const int& v) const
{
    return adj[v];
}

void Graph::print(ostream& os) const
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

int Graph::degree(const int& v) const
{
    int degree = 0;
    for (int w = 0; w < adj[v].size(); w++)
        degree++;
    return degree;
}

int Graph::maxDegree() const
{
    int maxd = -1;
    for (int v = 0, deg = degree(v); v < V; deg = degree(++v))
        if (maxd < deg)
            maxd = deg;
    return maxd;
}

int Graph::number0SelfLoops() const
{
    int count = 0;
    for (int v = 0; v < V; v++)
        for (int w = 0; w < adj[v].size(); w++)
            if (v == adj[v][w])
                count++;
    return count;
}
//--------------------------------------
Search::Search(const Graph& G, const int& s, const SearchMode& m)
{
    marked = new bool[G.rV()];
    edgeTo = new int[G.rE()];
    this->s = s;
    mode = m;
    if (mode)
        bfs(G);
    else
        dfs(G, s);
}

Search::~Search()
{
    delete[] marked;
    delete[] edgeTo;
}

void Search::dfs(const Graph& G, int v) const
{
    marked[v] = true;
    vector<int> node = G.radj(v);

    for (int w = 0; w < node.size(); w++)
        if (!marked[node[w]]) {
            edgeTo[node[w]] = v;
            dfs(G, node[w]);
        }
}

void Search::bfs(const Graph& G) const
{
    marked[s] = true;
    queue<int> que;
    que.push(s);
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        vector<int> node = G.radj(v);
        for (int w = 0; w < node.size(); w++)
            if (!marked[node[w]]) {
                edgeTo[node[w]] = v;
                marked[node[w]] = true;
                que.push(node[w]);
            }
    }
}
void Search::printPath(const int& v, ostream& os) const
{
    if (!hasPathTo(v)) {
        os << "No Path\n";
        return;
    }
    int stack[size];
    int top = 0;
    for (int x = v; x != s; x = edgeTo[x])
        stack[top++] = x;
    stack[top++] = s;
    os << "The path: " << s << "-" << v << " is: ";
    while (top != 0)
        os << stack[--top] << ' ';
    os << std::endl;
}

//================================================
CC::CC(const Graph& G)
{
    count = 0;
    id = new int[G.rV()];
    marked = new bool[G.rV()];
    for (int v = 0; v < G.rV(); v++)
        if (!marked[v]) {
            dfs(G, v);
            count++;
        }
}

CC::~CC()
{
    delete[] id;
    delete[] marked;
}
void CC::dfs(const Graph& G, int& v)
{
    marked[v] = true;
    id[v] = count;
    vector<int> node = G.radj(v);
    for (int w = 0; w < node.size(); w++)
        if (!marked[node[w]])
            dfs(G, node[w]);
}

bool CC::connected(const int& v, const int& w) const
{
    return id[v] == id[w];
}

int CC::rid(const int& v) const
{
    return id[v];
}

int CC::rcount() const
{
    return count;
}

//===============================================
Cycle::Cycle(const Graph& G)
{
    cycle = false;
    marked = new bool[G.rV()];
    edgeTo = new int[G.rV()];
    for (int v = 0; v < G.rV() && !cycle; v++)
        if (!marked[v])
            dfs(G, v);
}

Cycle::~Cycle()
{
    delete[] marked;
    delete[] edgeTo;
}
void Cycle::dfs(const Graph& G, const int& v)
{
    if (cycle)
        return;
    marked[v] = true;
    vector<int> node = G.radj(v);
    for (int w = 0; w < node.size(); w++)
        if (marked[node[w]] && node[w] != edgeTo[v])
            cycle = true;
        else if (!marked[node[w]]) {
            edgeTo[node[w]] = v;
            dfs(G, node[w]);
        }
}

//===============================================
TwoColor::TwoColor(const Graph& G)
{
    marked = new bool[G.rV()];
    colors = new bool[G.rV()];
    colors[0] = true;
    dfs(G, 0);
}

TwoColor::~TwoColor()
{
    delete[] marked;
    delete[] colors;
}

void TwoColor::dfs(const Graph& G, const int& v)
{
    if (iscolor)
        return;
    marked[v] = true;
    vector<int> node = G.radj(v);
    for (int w = 0; w < node.size(); w++)
        if (marked[node[w]]) {
            if (colors[node[w]] == colors[v]) {
                iscolor = true;
                break;
            }
        } else {
            colors[node[w]] = !colors[v];
            dfs(G, node[w]);
        }
}
