#include <iostream>
using namespace std;

int judge(int a, int b)
{
	switch(a)
	{
		case 0:
			switch(b)
			{
				case 0:
					return 0;
				case 1:
					return 2;
				case 2:
					return 1;
				case 3:
					return 1;
				case 4:
					return 2;
			}
			break;
		case 1:
			switch(b)
			{
				case 0:
					return 1;
				case 1:
					return 0;
				case 2:
					return 2;
				case 3:
					return 1;
				case 4:
					return 2;
			}
			break;
		case 2:
			switch(b)
			{
				case 0:
					return 2;
				case 1:
					return 1;
				case 2:
					return 0;
				case 3:
					return 2;
				case 4:
					return 1;
			}
			break;
		case 3:
			switch(b)
			{
				case 0:
					return 2;
				case 1:
					return 2;
				case 2:
					return 1;
				case 3:
					return 0;
				case 4:
					return 1;

			}
			break;
		case 4:
			switch(b)
			{
				case 0:
					return 1;
				case 1:
					return 1;
				case 2:
					return 2;
				case 3:
					return 2;
				case 4:
					return 0;

			}
			break;
	}
}

int main()
{
	int n, a, b;
	int a_[210], b_[210];
	int cnta = 0, cntb = 0;

	cin >> n >> a >> b;
	for(int i = 0; i < a; i++)
		cin >> a_[i];
	for(int i = 0; i < b; i++)
		cin >> b_[i];

	int j = 0;
	int k = 0;

	for(int i = 0; i < n; i++)
	{
		int ans = judge(a_[j], b_[k]);
		if(ans == 1)
			cnta++;
		else if (ans == 2)
			cntb++;
		j = (j + 1) % a;
		k = (k + 1) % b;
	}

	cout << cnta << ' ' << cntb;
}
