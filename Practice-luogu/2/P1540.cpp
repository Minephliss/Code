#include <iostream>
#include <vector>
using namespace std;

int m, n, cnt;

int main()
{
	cin >> m >> n;

	int num;
	vector<int> que;
	for(int i = 0; i < n; i++)
	{
		cin >> num;
		bool has = false;
		for(int j = 0; j < que.size(); j++)
			if(num == que[j])
				has = true;

		if(has)
			continue;

		cnt++;

		if(que.size() < m)
			que.push_back(num);
		else
		{
			que.erase(que.begin());
			que.push_back(num);
		}
	}
	cout << cnt;
}
