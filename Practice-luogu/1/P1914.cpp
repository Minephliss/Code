#include <string>
#include <iostream>
using namespace std;

int main()
{
	int n;
	string str;
	cin >> n >> str;
	for(int i = 0; i < str.length(); i++)
	{
		int p = str[i] + n;
		while(p > 'z')
			p-=26;
		str[i] = p;
	}
	cout << str;
	return 0;
}
