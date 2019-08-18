#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

string _reverse(string & str)
{
	while(str[0] == '0')
		str.erase(0, 1);
	reverse(str.begin(), str.end());

	while(str[0]=='0')
		str.erase(0, 1);

	if(str.length() == 0)
		str = "0";
	return str;
}

void copy(const string & str, string & tar, const int & start, const int & end)
{
	int i = start;
	while(str[i] == '0' && i < end)
		i++;

	for(int i = start; i < end; i++)
		tar += str[i];	
}

int main()
{
	string str;
	int mode =0;
	int pot;
	cin >> str;
	for(int i = 0; i < str.length(); i++)
	{
		if(str[i] < '0')
		{
			pot = i;
			if(str[i] == '.')
				mode = 1;
			else if(str[i] == '/')
				mode = 2;
			else if (str[i] == '%')
				mode = 3;
		}
	}
    string temp;
	switch(mode)
	{
		case 0:
			cout << _reverse(str);
			break;
		case 1:
			copy(str, temp, 0, pot);
			cout <<	_reverse(temp) << '.';
			temp = "";
			copy(str, temp, pot + 1, str.length());
			cout << _reverse(temp);
			break;
		case 2:
            copy(str, temp, 0, pot);
            cout << _reverse(temp) << '/';
            temp = "";
            copy(str, temp, pot + 1, str.length());
            cout << _reverse(temp);	
			break;
		case 3:
            copy(str, temp, 0, pot);
            cout << _reverse(temp) << '%';
	}
	return 0;	
}
