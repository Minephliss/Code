#include <iostream>
using namespace std;

int n;

void read()
{
    int cnt = 1;
    bool last = false;
    bool cur;
    cin >> n;
    while(n--)
    {
        cin >> cur;
        if(cur != last)
        {
            cnt++;
            last = cur;
        }
    }
    cout << cnt;
}

int main()
{
    read();
    return 0;
}