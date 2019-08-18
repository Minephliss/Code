#include <iostream>
#include <algorithm>
using namespace std;

int n, m;

struct Man
{
	int num;
	int mark;
	Man() { }
	Man(int a, int b)	{num = a; mark = b;}
	bool operator<(const Man & a) const
	{
		if(mark==a.mark)
			return num < a.num;
		return mark > a.mark;
	}	
};

int main()
{
	Man men[5000];
	int tar, cnt = 0;
	cin >> n >> m;

	for(int i = 0, a, b; i < n; i++)
	{
		cin >> a >> b;
		men[i] = Man(a, b);
	}

	sort(men, men + n);

	m = m + m / 2;

	tar = men[m - 1].mark;

	int i = 0;
	while(men[i++].mark >= tar)
		cnt++;

	cout << tar << ' ' << cnt << endl;
	for(i = 0; men[i].mark >= tar; i++, cnt++)
		cout << men[i].num << ' ' << men[i].mark << endl;

	return 0;
}
