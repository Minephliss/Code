#include <iostream>
using namespace std;

int main()
{
    int si[5100], hei[5100];
    int n, s, a, b, x, y, cnt = 0, num = 0;
    int he;
    cin >> n >> s;
    cin >> a >> b;
    he = a + b;
    for (int i = 0; i < n; i++) {
	cin >> x >> y;
	if (x <= he) {
	    hei[num] = x;
	    si[num++] = y;
	}
    }

    for (int i = 0; i < num; i++)
	for (int j = 0; j < i; j++) {
	    if (si[i] < si[j]) {
		int temp1 = si[i];
		int temp2 = hei[i];
		for (int k = i; k > j; k--) {
		    si[k] = si[k - 1];
		    hei[k] = hei[k - 1];
		}
		si[j] = temp1;
		hei[j] = temp2;
	    }
	}

    for (int i = 0; s - si[i] > 0; i++) {
	cnt++;
	s -= si[i];
    }

    cout << cnt;
}
