#include <iostream>
#include <cmath>
using namespace std;

const long long P = 10e9 + 7;

double lowbit(int i)
{
    return i&(~i + 1);
}

double log2(double i)
{
    return log(i) / log(2);
}

int main()
{
    int n;
    cin >> n;
    for(int k = 1; k <= n; k++)
    {
        double ans = 0;
        for(int i = pow(2, k), j = 1; i >= 1; i--, j++)
        {
                ans += i * log2(lowbit(j));
        }
        cout << ans << endl;
    }
}