#include <iostream>
#include <vector>
using namespace std;

#define lef rt << 1
#define rig rt << 1 | 1
#define lefs l, mid, rt << 1
#define rigs mid + 1, r, rt << 1 | 1
#define inf __INT_MAX__
#define maxn 100010

struct Node {
    int to;
    int d;
	Node() {}
    Node(int a, int b)
    {
		to = a;
		d = b;
    }
	bool operator<(const Node& a) const
	{
		return d < a.d;
	}

};

int N, M, S, aim;
int* dis;
Node tree[maxn * 4];
vector<Node>* map;

void Update(int rt)
{
	if(tree[lef].d < tree[rig].d)
        tree[rt] = tree[lef];
    else
        tree[rt] = tree[rig];
}

void Build(int l, int r, int rt)
{
    if (l == r)
		tree[rt] = Node(0, inf);
	else{
		int mid = (l + r) >> 1;
		Build(lefs);
		Build(rigs);
		Update(rt);
	}
}

void add(int l, int r, int rt, Node x)
{
	if(l == r)
		tree[rt] = x;
	else
	{
		int mid = (l + r) >> 1;
		if(aim < mid)
			add(lefs, x);
		else
			add(rigs, x);
		Update(rt);
	}
}

void del(int l, int r, int rt)
{
	if(l == r)
		tree[rt].d = inf;
	else
	{
		int mid = (l + r) >> 1;
		if(tree[lef].d < tree[rig].d)
			del(lefs);
		else
			del(rigs);
		Update(rt);
	}
}

void init()
{
	for(int i = 0; i <= N; i++)
		dis[i] = inf;	
}

void Dijkstra(int start)
{
	init();
	dis[start] = 0;
	aim	= start;
	add(1, N, 1, Node(start, dis[start]));
	while(tree[1].d != inf)
	{
		Node v = tree[1];
		del(1, N, 1);
		if(dis[v.to]!=v.d)
			continue;
		for(unsigned i = 0; i < map[v.to].size(); i++)
		{
			Node w = map[v.to][i];
			if(dis[w.to] > w.d + v.d)
			{
				dis[w.to] = w.d + v.d;
				aim = w.to;
				add(1, N, 1, Node(w.to, dis[w.to]));
			}
		}
	}
}

void read()
{
	cin >> N >> M >> S;
	int a, b, c;
	map = new vector<Node>[N + 1];
	dis = new int[N + 1];
	for(int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		map[a].push_back(Node(b, c));
	}
}

int main()
{
	read();

	Build(1, N, 1);

	Dijkstra(S);

	for(int i = 1; i <= N; i++)
		cout << dis[i] << ' ';

	delete[] dis;
	delete[] map;
	return 0;
}
