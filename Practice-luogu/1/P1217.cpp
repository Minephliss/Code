#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int a, b;

bool judge(int num);
bool tell;
void create(int n, int* A, int cur);

int main()
{
    int A[9];
    int ca = 0, cb = 0;
    cin >> a >> b;
    int ta = a;
    int tb = b;
    if (b >= 100000000)
	b = 10000000 - 1;
    while (ta > 0) {
	ta /= 10;
	ca++;
    }
    while (tb > 0) {
	tb /= 10;
	cb++;
    }
    for (int i = ca; i <= cb; i++)
	create(i, A, 0);
}
void create(int n, int* A, int cur)
{
    if (tell)
	return;
    if (cur == (n + 1) / 2) {
	int i, j, k = 0, num = 0;
	for (i = 1, j = pow(10, n - 1); i <= j; i *= 10, j /= 10, k++) {
	    if (i != j) {
		num += i * A[k];
		num += j * A[k];
	    } else
		num += i * A[k];
	}

	if (judge(num) && num >= a && num <= b)
	    cout << num << endl;
	if (num == 9989899)
	    tell = true;
    } else {
	for (int i = 0; i < 10; i++) {
	    if ((cur == 0 && i != 0) || cur != 0) {
		A[cur] = i;
		create(n, A, cur + 1);
	    }
	}
    }
}

bool judge(int num)
{
    if (num == 5)
	return true;
    if (num % 2 == 0 || num % 5 == 0)
	return false;
    for (int i = 2; i <= sqrt(num); i++)
	if ((num / i) * i == num)
	    return false;
    return true;
}
