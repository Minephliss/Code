#include <cstring>
#include <iostream>
using namespace std;

bool marked[10];
bool judge(int a, int b, int c);
bool ans;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    for (int a1 = 1; a1 / a * c < 10000000; a1++) {
	if (a1 / a * a != a1)
	    continue;
	int b1 = a1 / a * b;
	int c1 = a1 / a * c;
	if (judge(a1, b1, c1)) {
	    ans = true;
	    cout << a1 << ' ' << b1 << ' ' << c1 << endl;
	}
    }
    if (!ans)
	cout << "No!!!";
}

bool judge(int a, int b, int c)
{
    memset(marked, false, sizeof(marked));
    marked[0] = true;

    while (a > 0) {
	if (marked[a % 10])
	    return false;
	else
	    marked[a % 10] = true;
	a /= 10;
    }

    while (b > 0) {
	if (marked[b % 10])
	    return false;
	else
	    marked[b % 10] = true;
	b /= 10;
    }

    while (c > 0) {
	if (marked[c % 10])
	    return false;
	else
	    marked[c % 10] = true;
	c /= 10;
    }
    for (int i = 0; i < 10; i++)
	if (!marked[i])
	    return false;
    return true;
}
