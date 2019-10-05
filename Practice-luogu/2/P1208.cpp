#include <iostream>
#include <queue>
using namespace std;
struct MilkFarmer
{
	int cost;
	int quantity;
	MilkFarmer(int a = 0, int b = 0)	{cost = a; quantity = b;}
	bool operator<(const MilkFarmer & a) const
	{
		return cost > a.cost;
	}
};

int n, m, temp, sum;
priority_queue<MilkFarmer> que;

int main()
{
	int x, y;
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		cin >> x >> y;
		que.push(MilkFarmer(x, y));
	}

	while(!que.empty())
	{
		MilkFarmer mf = que.top();
		que.pop();
		if(mf.quantity + temp <= n)
		{
			sum = sum + mf.cost * mf.quantity;
			temp += mf.quantity;
		}
		else
		{
			sum = sum + mf.cost * (n - temp);
			temp = n;
			break;
		}
	}
	if(temp == n)
		cout << sum;

	return 0;
}

