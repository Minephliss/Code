#include <iostream>
using namespace std;

int main()
{
    int n;
    int num, p;
    cin >> n;
    p = n;
    for (int i = 0; i <= n; i++) {
	cin >> num;
	if (num > 1 || num < -1) {
	    if (i != 0 && num > 0)
		cout << '+';
	    cout << num;
	} else if (num == 1 || num == -1) {
	    if (num == 1) {
		if (i == 0) {
		    if (p == 0)
			cout << num;
		} else {
		    if (p == 0)
			cout << '+' << num;
		    else
			cout << '+';
		}
	    } else {
		if (p == 0)
		    cout << num;
		else
		    cout << '-';
	    }
	} else {
	    p--;
	    continue;
	}

	if (p > 1) {
	    cout << "x^" << p--;
	} else if (p == 1) {
	    cout << 'x';
	    p--;
	} else
	    p--;
    }
}
