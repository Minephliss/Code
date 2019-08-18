#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

int str_num(string str)
{
	int ans = 0;
	while(!str.empty())
	{
		ans = ans + (str[0] - '0') * pow(10, str.length() - 1);
		str.erase(str.begin());
	}
	return ans;
}

int anal(string str)
{
	if(str[2] == '1')
		return 0;

	string temp;
	for(int i = 4; str[i] != ')'; i++)
		temp += str[i];
	return str_num(temp);
}

void mark_E(bool * me, bool * mf, string str, int p, bool tell)
{
	int cnt = 1;
	while(cnt > 0)
	{
		p++;
		if(str[p] == 'F')
		{
			cnt++;
			if(tell)
				mf[p] = false;
		}
		else
		{
			cnt--;
			if(tell)
				me[p] = false;
		}
	}
	me[p] = false;
}

bool find(char * arr, int si, char tar)
{
	for(int i = 0; i < si; i++)
		if(arr[i] == tar)
			return true;
	return false;
}

int main()
{
	int t, line, it;
	char I[100], stk[26];
	string chk, X[100], Y[100];
	bool tell, marked_E[100], marked_F[100];
	cin >> t;
	while(t-- > 0)
	{
		it = 0;
		string p, temp;
		stringstream pro;

		cin >> line >> chk;
		getchar();
		for(int i = 0; i < line; i++, pro << temp << ' ')
			getline(cin, temp);

		while(pro >> temp)
		{
			p+=temp;
			if(temp[0] == 'F')
				pro >> I[it] >> X[it] >> Y[it++];
		}

		int cntf = 0, cnt = 0, ma = 0, i2 = 0, top = 0;
		tell = false;

		memset(stk, ' ', sizeof(stk));
		memset(marked_E, true, sizeof(marked_E));
		memset(marked_F, true, sizeof(marked_F));
		
		for(unsigned i = 0; i < p.length(); i++)
		{
			if(p[i] == 'F')
			{
				cnt++;
				if(top && find(stk, top, I[i2]))
				{
					tell = true;
					break;	
				}
				stk[top++] = I[i2];

				if(Y[i2] == "n"&&X[i2] != "n" && marked_F[i])
					cntf++;
				else if((X[i2] == "n" && Y[i2] != "n") || (str_num(X[i2]) > str_num(Y[i2])))
					mark_E(marked_E,marked_F, p, i, 1);
				else
					mark_E(marked_E,marked_F, p, i, 0);
				
				i2++;
			}
			else
			{
				cnt--;
				top--;
				if(marked_E[i])
					cntf--;
			}

			if(cntf < 0)
			{
				tell = true;
				break;
			}

			ma = max(ma, cntf);
		}

		if(tell || cnt != 0)
		{
			cout << "ERR" << endl;
			continue;
		}
		
		if(ma == anal(chk))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	
	} 
	return 0;
}
