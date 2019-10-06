#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int maxn, n, x, arr[30010], sum = 0;
	bool map[30010];
	cin >> maxn >> n;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	
	for(int i = 0; i < 30010; i++)
		map[i] = true;

	sort(arr, arr + n);
	
	for(int i = 0; i < n; i++)
	{
		if(map[i])
		{
			int j;
			for(j = n - 1; j > i; j--)
				if(map[j] && arr[i] + arr[j] <= maxn)
				{
					map[j] = false;
					map[i] = false;
					sum++;
					break;
				}
			if(i == j)
			{
				sum++;
				map[i] = false;
			}
		}
	}

	cout << sum;

	return 0;
}
