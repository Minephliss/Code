#include <iostream>
using namespace std;

int main()
{
    int n;
    int cnt[31] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 10, 55, 210, 615, 1452, 2850, 4740, 6765, 8350, 8953, 8350, 6765, 4740, 2850, 1452, 615, 210, 55, 10, 1 };
    cin >> n;
    if (n > 30 || n < 10) {
	cout << 0;
	return 0;
    }
    cout << cnt[n] << endl;
    for (int d1 = 1; d1 < 4; d1++)
	for (int d2 = 1; d2 < 4; d2++)
	    for (int d3 = 1; d3 < 4; d3++)
		for (int d4 = 1; d4 < 4; d4++)
		    for (int d5 = 1; d5 < 4; d5++)
			for (int d6 = 1; d6 < 4; d6++)
			    for (int d7 = 1; d7 < 4; d7++)
				for (int d8 = 1; d8 < 4; d8++)
				    for (int d9 = 1; d9 < 4; d9++)
					for (int d10 = 1; d10 < 4; d10++)
					    if (n == d1 + d2 + d3 + d4 + d5 + d6 + d7 + d8 + d9 + d10)
						cout << d1 << ' ' << d2 << ' ' << d3 << ' ' << d4 << ' ' << d5 << ' ' << d6 << ' '
						     << d7 << ' ' << d8 << ' ' << d9 << ' ' << d10 << endl;
}
