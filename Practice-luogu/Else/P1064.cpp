#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int dp[32001];
bool bought[61];

struct Item {
    int num;
    int price;
    int value;
    int fa;
	bool operator<(const Item& a) const
	{
		return fa < a.fa;
	}
} items[60];

void read()
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        items[i].num = i;
        cin >> items[i].price >> items[i].value >> items[i].fa;
        items[i].fa--;
    }
	sort(items, items + m);
}


void solve()
{
	for(int i = 0; i < n + 1; i++)
		for(int j = 0; j < m; j++)
			if(items[j].fa == -1 || bought[items[j].fa])
				if(i >= items[j].price)
				{
					dp[i] = max(dp[i - items[j].price] + items[j].value * items[j].price, dp[i]);
					if(dp[i] == dp[i - items[j].price] + items[j].value)
						bought[j] = true;
					else
						bought[j] = false;
				}
				else
					bought[j] = false;
			else
				bought[j] = false;
	cout << dp[n] << endl;
}

int main()
{
	read();

    solve();

    return 0;
}
