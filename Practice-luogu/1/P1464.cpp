#include <cstring>
#include <iostream>
using namespace std;

int mem[21][21][21];

long long w(long long a, long long b, long long c)
{
    if (a <= 0 || b <= 0 || c <= 0)
	return 1;
    else if (a > 20 || b > 20 || c > 20)
	return w(20, 20, 20);

    if (mem[a][b][c] != -1)
	return mem[a][b][c];
    if (a < b && b < c)
	return mem[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    else
	return mem[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main()
{
    long long a, b, c;
    cin >> a >> b >> c;

    memset(mem, -1, sizeof(mem));

    while (a != -1 || b != -1 || c != -1) {
	cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << endl;
	cin >> a >> b >> c;
    }
}
