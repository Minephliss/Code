#include <iostream>
#include <algorithm>
using namespace std;

int n, k, D[20000], E[20000];

struct Per
{
	int val;
	int num;
	int rank;
	bool operator<(const Per &a) const
	{
		if(val != a.val)
			return val > a.val;
		return num < a.num;
	}
};

Per W[20000];

void read()
{
	cin >> n >> k;
	for(int i = 1; i <= 10; i++)
		cin >> E[i];
	for(int i = 0; i < n; i++)
	{
		cin >> W[i].val;
		W[i].num = i + 1;
	}
}

int main()
{
	read();
	sort(W, W + n);
	for(int i = 0; i < n; i++)
	{
		W[i].rank = i + 1;
		W[i].val = W[i].val + E[(W[i].rank - 1) % 10 + 1];
	}
	sort(W, W + n);
	for(int i = 0; i < k; i++)
		cout << W[i].num << ' ';
}
