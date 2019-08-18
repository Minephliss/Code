#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
	string str;
	int cnt[26] = {0};
	for(int i = 0; i < 4; i++)
	{
		getline(cin, str);
		for(int j = 0; j < str.length(); j++)
			if(str[j] <= 'Z' && str[j] >= 'A')
				cnt[str[j] - 'A']++;
	}

	int mh = 0;
	for(int i = 0; i < 26; i++)
		mh = max(mh, cnt[i]);
	for(int i = mh; i > 0; i--)
	{
		for(int j = 0; j < 26; j++)
		{
			if(cnt[j] >= i)	cout << "* ";
			else			cout << "  ";
		}	
		cout << endl;
	}
	
	for(char i = 'A'; i < 'Z' + 1; i++)
		cout << i << ' ';
	return 0;
}
