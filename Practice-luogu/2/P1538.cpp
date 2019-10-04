#include <iostream>
#include <string>
using namespace std;

int main()
{
	int si, i;
	string num;
	cin >> si >> num;

	for(i = 0; i < num.size(); i++)
	{
		cout << ' ';
		switch(num[i])
		{
			case '1':
				for(int j = 0; j < si; j++)
					cout << ' ';
				break;
			case '2':
				for(int j = 0; j < si; j++)
					cout << '-';
				break;
			case '3':
				for(int j = 0; j < si; j++)
					cout << '-';
				break;
			case '4':
				for(int j = 0; j < si; j++)
					cout << ' ';
				break;
			case '5':
				for(int j = 0; j < si; j++)
					cout << '-';
				break;
			case '6':
				for(int j = 0; j < si; j++)
					cout << '-';
				break;
			case '7':
				for(int j = 0; j < si; j++)
					cout << '-';
				break;
			case '8':
				for(int j = 0; j < si; j++)
					cout << '-';
				break;
			case '9':
				for(int j = 0; j < si; j++)
					cout << '-';
				break;
			case '0':
				for(int j = 0; j < si; j++)
					cout << '-';
				break;
		}
		if(i != num.size() - 1);
			cout << "  ";
	}
	cout << endl;
//-------------------------------step #2-------------------------------------------
	for(int k = 0; k < si; k++)
	{
		for(i = 0; i < num.size(); i++)
		{
			switch(num[i])
			{
				case '1':
					for(int j = 0; j < si + 1; j++)
						cout << ' ';
					cout << '|';
					break;
				case '2':
					for(int j = 0; j < si + 1; j++)
						cout << ' ';
					cout << '|';
					break;
				case '3':
					for(int j = 0; j < si + 1; j++)
						cout << ' ';
					cout << '|';
					break;
				case '4':
					cout << '|';
					for(int j = 0; j < si; j++)
						cout << ' ';
					cout << '|';
					break;
				case '5':
					cout << '|';
					for(int j = 0; j < si + 1; j++)
						cout << ' ';
					break;
				case '6':
					cout << '|';
					for(int j = 0; j < si + 1; j++)
						cout << ' ';
					break;
				case '7':
					for(int j = 0; j < si + 1; j++)
						cout << ' ';
					cout << '|';
					break;
				case '8':
					cout << '|';
					for(int j = 0; j < si; j++)
						cout << ' ';
					cout << '|';
					break;
				case '9':
					cout << '|';
					for(int j = 0; j < si; j++)
						cout << ' ';
					cout << '|';
					break;
				case '0':
					cout << '|';
					for(int j = 0; j < si; j++)
						cout << ' ';
					cout << '|';
					break;
			}
			if(i != num.size() - 1);
				cout << ' ';
		}
		cout << endl;
	}

//------------------------step #3---------------------------
	for(i = 0; i < num.size(); i++)
	{
		cout << ' ';
		switch(num[i])
		{
			case '1':
				for(int j = 0; j < si; j++)
					cout << ' ';
				break;
			case '2':
				for(int j = 0; j < si; j++)
					cout << '-';
				break;
			case '3':
				for(int j = 0; j < si; j++)
					cout << '-';
				break;
			case '4':
				for(int j = 0; j < si; j++)
					cout << '-';
				break;
			case '5':
				for(int j = 0; j < si; j++)
					cout << '-';
				break;
			case '6':
				for(int j = 0; j < si; j++)
					cout << '-';
				break;
			case '7':
				for(int j = 0; j < si; j++)
					cout << ' ';
				break;
			case '8':
				for(int j = 0; j < si; j++)
					cout << '-';
				break;
			case '9':
				for(int j = 0; j < si; j++)
					cout << '-';
				break;
			case '0':
				for(int j = 0; j < si; j++)
					cout << ' ';
				break;
		}
		if(i != num.size() - 1);
			cout << "  ";
	}
	cout << endl;
//--------------------------------------step #4------------------------------------
	for(int k = 0; k < si; k++)	
	{	
		for(i = 0; i < num.size(); i++)
		{
			switch(num[i])
			{
				case '1':
					for(int j = 0; j < si + 1; j++)
						cout << ' ';
					cout << '|';
					break;
				case '2':
					cout << '|';
					for(int j = 0; j < si + 1; j++)
						cout << ' ';
					break;
				case '3':
					for(int j = 0; j < si + 1; j++)
						cout << ' ';
					cout << '|';
					break;
				case '4':
					for(int j = 0; j < si + 1; j++)
						cout << ' ';
					cout << '|';
					break;
				case '5':
					for(int j = 0; j < si + 1; j++)
						cout << ' ';
					cout << '|';
					break;
				case '6':
					cout << '|';
					for(int j = 0; j < si; j++)
						cout << ' ';
					cout << '|';
					break;
				case '7':
					for(int j = 0; j < si + 1; j++)
						cout << ' ';
					cout << '|';
					break;
				case '8':
					cout << '|';
					for(int j = 0; j < si; j++)
						cout << ' ';
					cout << '|';
					break;
				case '9':
					for(int j = 0; j < si + 1; j++)
						cout << ' ';
					cout << '|';
					break;
				case '0':
					cout << '|';
					for(int j = 0; j < si; j++)
						cout << ' ';
					cout << '|';
					break;
			}
			if(i != num.size() - 1);
				cout << ' ';
		}
		cout << endl;
	}
//-------------------------------step #5---------------------------------------
	for(i = 0; i < num.size(); i++)
	{
		cout << ' ';
		switch(num[i])
		{
			case '1':
				for(int j = 0; j < si; j++)
					cout << ' ';
				break;
			case '2':
				for(int j = 0; j < si; j++)
					cout << '-';
				break;
			case '3':
				for(int j = 0; j < si; j++)
					cout << '-';
				break;
			case '4':
				for(int j = 0; j < si; j++)
					cout << ' ';
				break;
			case '5':
				for(int j = 0; j < si; j++)
					cout << '-';
				break;
			case '6':
				for(int j = 0; j < si; j++)
					cout << '-';
				break;
			case '7':
				for(int j = 0; j < si; j++)
					cout << ' ';
				break;
			case '8':
				for(int j = 0; j < si; j++)
					cout << '-';
				break;
			case '9':
				for(int j = 0; j < si; j++)
					cout << '-';
				break;
			case '0':
				for(int j = 0; j < si; j++)
					cout << '-';
				break;
		}
		if(i != num.size() - 1);
			cout << "  ";
	}
	return 0;
}
