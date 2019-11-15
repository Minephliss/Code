#include <iostream>
using namespace std;

int FastPower(int a, int n, int mod)
{
    int c = 1;
    while(n)
    {
        if(n & 1)
            c = (c * a) % mod;
        a = (a * a) % mod;
        n >>= 1;
    }
    return c;
}

int main()
{
    int a, n, mod;
    cin >> a >> n >> mod;
    cout << FastPower(a, n, mod);
    return 0;
}
