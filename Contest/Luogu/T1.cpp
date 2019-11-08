#include <iostream>
#include <map>
using namespace std;

map<long long, long long> arr;
long long n;
long long res;
long long solve(long long n)
{
    if(arr.count(n))
        return arr[n];
    long long t = n / 2;
    if(t * 2 != n)
        return arr[n] = solve(t) + solve(t + 1) + 2 * t;
    else
        return arr[n] = 2*solve(n / 2) + 2 * t - 1;
}

int main()
{
    cin >> n;
    arr[1] = 0;
    arr[2] = 1;
    arr[3] = 3;
    arr[4] = 5;
    arr[5] = 8;
    cout << solve(n);
    return 0;
}