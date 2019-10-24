#include <iostream>
#include <queue>
using namespace std;

const int maxn = 100000;

int V, E, S;
int * dis;
int * cnt;
bool * inq;

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

vector<Node> * map;

void init()
{
    for (int i = 0; i < V; i++)
	{
        dis[i] = __INT_MAX__;
		cnt[i] = 0;
		inq[i] = false;
	}
}

void read()
{
    int a, b, c;
    cin >> V >> E >> S;
	S--;

	inq = new bool[V];
	cnt = new int[V];
	dis = new int[V];
	map = new vector<Node>[V];

    for (int i = 0; i < E; i++) {
        cin >> a >> b >> c;
        map[a - 1].push_back(Node(b - 1, c));
    }
}

bool BellmanFord(int start)
{
	init();
	queue<Node> Q;
	dis[start] = 0;
	Q.push(Node(start, dis[start]));
	inq[start] = true;

	while(!Q.empty())
	{
		Node v = Q.front();
		Q.pop();
		inq[v.to] = false;

		for(unsigned i = 0; i < map[v.to].size(); i++)
		{
			Node w = map[v.to][i];
			if(v.d < __INT_MAX__ && dis[w.to] > v.d + w.d)
			{
				dis[w.to] = v.d + w.d;
				if(!inq[w.to])
				{
					Q.push(Node(w.to, dis[w.to]));
					inq[w.to] = true;
					if(++cnt[v.to] > V)
						return false;
				}
			}
		}
	}
	return true;
}

int main()
{
	read();
	if(BellmanFord(S))
		for(int i = 0; i < V; ++i)
			cout << dis[i] << ' ';
	else
		cout << "Has minus cycle!";

	delete[] dis;
	delete[] cnt;
	delete[] inq;
	return 0;	
}
