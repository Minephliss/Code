#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	int cnt = 0;
	bool tell = false;
	map<char, char> keys;
	string a, b, c;
	cin >> a >> b >> c;

	if(a.length() != b.length())
		tell = true;
	else
		for(int i = 0; i < a.length(); i++)
		{
			if(keys.count(a[i]))
			{
				if(b[i] != keys[a[i]])
				{
					tell = true;
					break;
				}
			}
			else if(a[i] != ' ')
				keys[a[i]] = b[i];
		}

	if(keys.size()!=26)
		tell = true;

	if(tell)
		cout << "Failed" << endl;
	else
		for(int i = 0; i < c.length(); i++)
			cout << keys[c[i]];
}
