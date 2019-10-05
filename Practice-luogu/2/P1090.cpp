#include <iostream>
#include <queue>
using namespace std;

int n;
priority_queue<int, vector<int>, greater<int> > que;

int main()
{
	int x, a, b;
	long sum = 0;

	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> x;
		que.push(x);
	}

	while(que.size() > 1)
	{
		a = que.top();
		que.pop();
		b = que.top();
		que.pop();
		sum = sum + a + b;
		que.push(a + b);
	}

	cout << sum;

	return 0;
}
