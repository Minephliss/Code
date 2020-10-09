#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	srand(time(0));
	int num, leng;
	cin >> num >> leng;
	for(int i = 0; i < num; i++)
	{
		for(int j = 0; j < leng; j++)
		{
			int p = rand() % 16;
			switch(p)
			{
				case 10:
					cout << 'A';
					break;
				case 11:
					cout << 'B';
					break;
				case 12:
					cout << 'C';
					break;
				case 13:
					cout << 'D';
					break;
				case 14:
					cout << 'E';
					break;
				case 15:
					cout << 'F';
					break;
				default:
					cout << p;
			}
		}
		cout << endl;
	}
	
	return 0;	
}
