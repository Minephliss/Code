#include <iostream>
#include <cctype>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
	int p1, p2, p3;
	string str;
	cin >> p1 >> p2 >> p3 >> str;

	for(int i = 0;i < str.length();i++)
	{
		if(str[i] == '-'&&i!=0&&i!=str.length() - 1 && str[i - 1]!='-'&&str[i] + 1!='-')
		{
			if(str[i - 1] < str[i + 1] && ((str[i - 1] >= 'a' && str[i + 1] <= 'z') || (str[i - 1] >= '0' && str[i + 1] <= '9')))
			{
				str.erase(str.begin() + i);
				if(str[i] - str[i - 1] > 1)
				{
					int temp = i; 
					int num = str[i] - str[i - 1];
					while(str[i - 1] != str[i] - 1 && num>1)
					{
						char ch = str[i - 1] + 1;
						if(p1 == 2)
							ch = toupper(ch);
						else if(p1 == 3)
							ch = '*';

						str.insert(str.begin() + i, p2, ch);
						i += p2;

						num--;

						if(p1 == 2 && str[i - 1] == toupper(str[i]) - 1)
							break;
					}

					if(p3 == 2)
						reverse(str.begin() + temp, str.begin() + i);
				}
			}
		}
	}
	cout << str;

	return 0;
}
