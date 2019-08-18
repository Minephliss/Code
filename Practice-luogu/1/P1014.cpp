#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int up = 3, i = 0;
    int key = 1;
    int tell = false;
    for (int i = 1; i < n; i++) {
	if (!tell && key == 1) {
	    tell = true;
	} else if (tell && key == up) {
	    tell = false;
	    up += 2;
	    key--;
	} else if (!tell) {
	    key--;
	} else if (tell) {
	    key++;
	}
    }

    cout << key << '/';

    up = 2, i = 0;
    key = 1;
    tell = false;
    for (int i = 1; i <= n; i++) {
	if (!tell && key == 1) {
	    tell = true;
	} else if (tell && key == up) {
	    tell = false;
	    up += 2;
	    key--;
	} else if (!tell) {
	    key--;
	} else if (tell) {
	    key++;
	}
    }

    cout << key;
}
