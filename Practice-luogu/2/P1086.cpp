#include <iostream>
#include <queue>
using namespace std;

struct T{
	int val;
	int x;
	int y;
	T() { }
	T(int a, int b, int c)	{val = a; x = b; y = c;}
	bool operator<(const T & a) const
	{
		return val < a.val;
	}
	T operator=(const T & a)
	{
		val = a.val;
		x = a.x;
		y = a.y;
	}
};

priority_queue<T> que;

int ti(const T & a, const T & b)	{return abs(a.x - b.x) + abs(a.y - b.y);}

int main()
{
	int M, N, K;
	
	cin >> M >> N >> K;
	
	if(K == 0)
	{
		cout << 0;
		return 0;
	}

	int v;
	for(int i = 1; i <= M; i++)
		for(int j = 1; j <= N; j++)
		{
			cin >> v;	
			if(v != 0)
				que.push(T(v, i, j));
		}
	
	T now(0, 1, que.top().y);
	K--;

	while(K >= 0)
	{
		if(que.empty()) break;

		if(K - ti(now, que.top()) - 1 - que.top().x >= 0)
		{
			K = K - ti(now, que.top()) - 1;
			now.val += que.top().val;
			now.x = que.top().x;
			now.y = que.top().y;
			que.pop();
		}
		else
			break;
	}

	cout << now.val;
}

