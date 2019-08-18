#include <iostream>
using namespace std;

int main()
{
	int n, sum = 0, cnt = 0;
	int tar;
	int arr[110];
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}

	tar = sum / n;

	int a1[110], a2[110];
	for(int i = 0 ; i < n; i++)
	{
		a1[i] = arr[i];
		a2[i] = arr[i];
	}

	for(int i = 0; i < n; i++)
	{
		if(a1[i] == tar)	continue;
		else if(a1[i] > tar)
		{
			a1[i + 1] = a1[i+1] + a1[i] - tar;
			a1[i] = tar;
			cnt++;
		}
		else if(a1[i] < tar)
		{
			int need = tar - a1[i];
			int avi = 0;
			for(int j = i+1; j < n; j++)
				if(a1[j] >= tar)
				{
					if(avi + a1[j] - tar >= need)
					{
						a1[j] = avi + a1[j] - need;
						cnt = cnt + j - i;
						i = j - 1;
						break;
					}
					else
					{
						avi = avi + a1[j] - tar;
						a1[j] = tar;
					}
				}
				else
				{
					need = need + tar - a1[j];
					a1[j] = tar;
				}
		}
	}

	cout << cnt;
}
