#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <map>
#include <cctype>

using namespace std;

priority_queue<int, vector<int>, greater<int>> que;

int main()
{
	bool fok = false;
	string ss, str;
	getline(cin, ss);
	stringstream strin(ss);
	map<string, int> s_n = {{"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"six", 6},{"seven", 7}, {"eight", 8},{"nine", 9}, {"ten", 10},{"eleven", 11}, {"twelve", 12},{"thirteen", 13}, {"fourteen", 14},{"fifteen", 15}, {"sixteen", 16},{"seventeen", 17}, {"eighteen", 18}, {"nineteen", 19}, {"twenty", 20}, {"a", 1}, {"both", 2}, {"another", 1}, {"first", 1}, {"second", 2}, {"third", 3}};

	while(strin >> ss)
	{
		if(ss[0] != '.')
		{
			ss[0] = tolower(ss[0]);
			if(s_n.count(ss))
				que.push(s_n[ss] * s_n[ss] % 100);
		}
	}

	if(que.empty())
	{
		cout << 0;
		return 0;
	}
	while(!que.empty())
	{
		if(fok)
		{
			if(que.top() < 10)
				cout << '0';
			if(que.top() == 0)
				cout << '0';
			cout << que.top();
			que.pop();
		}
		else
		{
			if(que.top()!=0)
			{
				cout << que.top();
				fok = true;
			}
			que.pop();
		}
	}
	return 0;
}
