#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct Man
{
	int num;
	string mark;
	bool operator<(const Man &a) const
	{
		if(mark.length()!=a.mark.length())
			return mark.length() > a.mark.length();
		return mark > a.mark;
	}
};

int main()
{
	int n, temp;
	Man men[100];
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		men[i].num = i + 1;
		cin >> men[i].mark;
	}

	sort(men, men + n);

	cout << men[0].num << endl << men[0].mark;
}
