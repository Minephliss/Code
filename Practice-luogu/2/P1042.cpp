#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	fstream fout("out2");

	char A[62510];
	int n = 0;
	A[n++] = getchar();
	if(A[0] == 'E')
		fout << "0:0\n\n0:0";
	else
	{
		while(A[n - 1] != 'E')
		{
			A[n++] = getchar();
			if(A[n - 1] == '\n')
				n--;
		}
		n--;

		int cnta = 0;
		int cntb = 0;
		bool tell = false;

		for(int i = 0; i < n; i++)
		{
			if(A[i] == 'W')
				cnta++;
			else
				cntb++;
			
			if(cnta == cntb && cnta == 10)
				tell = true;

			if(tell)
			{
				if(abs(cnta - cntb) == 2)
				{
					fout << cnta << ":" << cntb << endl;
					cnta = 0;
					cntb = 0;
					tell = false;
				}
			}
			else if(cnta == 11 || cntb == 11){
					fout << cnta << ":" << cntb << endl;
				cnta = 0;
				cntb = 0;
			}
		}
		if(cnta || cntb)
			fout << cnta << ":" << cntb << endl;
		
		fout << endl;
		
		cnta = 0;
		cntb = 0;
		tell = false;

		for(int i = 0; i < n; i++)
		{
			if(A[i] == 'W')
				cnta++;
			else
				cntb++;
			
			if(cnta == cntb && cnta == 20)
				tell = true;

			if(tell)
			{
				if(abs(cnta - cntb) == 2)
				{
					fout << cnta << ":" << cntb << endl;
					cnta = 0;
					cntb = 0;
					tell = false;
				}
			}
			else if(cnta == 21 || cntb == 21){
					fout << cnta << ":" << cntb << endl;
				cnta = 0;
				cntb = 0;
			}
		}
		if(cnta || cntb)
			fout << cnta << ":" << cntb << endl;
		
	
	}

}
