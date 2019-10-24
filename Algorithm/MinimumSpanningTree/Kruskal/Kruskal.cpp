#include <iostream>
#include <queue>
using namespace std;

struct Edge {
    int from, to, dis;
    Edge(int a, int b, int c)
        : from(a)
        , to(b)
        , dis(c)
    {
    }
    bool operator>(const Edge& e) const
    {
        return dis > e.dis;
    }
};

const int maxn = 10000;

priority_queue<Edge, vector<Edge>, greater<Edge>> que;
int sum, N, M;
int* fa;
int* hei;

int find(int ch) { return fa[ch] == ch ? ch : find(fa[ch]); }

void init()
{
    for (int i = 0; i < N; i++) {
        fa[i] = i;
        hei[i] = 0;
    }
}

bool uni(int a, int b)
{
    int x = find(a);
    int y = find(b);
    if (x != y) {
        if (hei[x] < hei[y])
            swap(x, y);
        fa[y] = x;
        if (hei[x] == hei[y])
            hei[x]++;

        return true;
    }
    return false;
}

void read()
{
    cin >> N >> M;
    int a, b, c;
    fa = new int[N];
    hei = new int[N];
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        que.push(Edge(a - 1, b - 1, c));
    }
}

void Kruskal()
{
    int cnt = 0;
    init();
    while (!que.empty()) {
        Edge e = que.top();
        que.pop();

        if (uni(e.from, e.to)) {
            if (cnt > N - 1)
                break;
            cnt++;
            sum += e.dis;
        }
    }
    if (cnt == N - 1)
        cout << sum;
    else
        cout << "orz";
}

int main()
{
    read();

    Kruskal();

    delete[] fa;
    delete[] hei;
    return 0;
}
