#include <iostream>
#include <queue>
using namespace std;

const int maxn = 200000;
int n;
vector<int> map[maxn];
bool mark[maxn];

int bfs(int s)
{
	int ans = 0, pos = s;
	for(int i = 0; i < n; i++)
		mark[i] = false;

	queue<int> que;
	mark[s] = true;
	que.push(s);
	while(!que.empty())
	{
		int v = que.front();
		que.pop();
		for(int i = 0; i < (int)map[v].size(); i++)
		{
			bool ok = true;
			int w = map[v][i];
			if(w == s)	return ++ans;
			if(!mark[w])
			{
				if(v == pos && ok)
				{
					ans++;
					pos = w;
				}
				mark[w] = true;
				que.push(w);
			}
		}
	}
	return -1;
}

int main()
{
    cin >> n;
	int p;
    for (int i = 0; i < n; i++)
	{
		cin >> p;
		map[i].push_back(p-1);
	}
	
	priority_queue<int, vector<int>, greater<int> > que;
	int val;
	for(int i = 0; i < n; i++)
	{
		val = bfs(i);
		if(val != -1)
			que.push(val);
	}
	cout << que.top();
}
