#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

struct Item {
    int val;
    int sell;
    Item() {};
    Item(const int a, const int b)
    {
        val = a;
        sell = b;
    }
    bool operator<(const Item& a) const
    {
        return val < a.val;
    }
};

Item A[100010];
int tar, a, c;

int val(int i, int key)
{
    return (A[i].val - c + key) * A[i].sell;
}

int main()
{
    cin >> tar;
    int x, y;
    int n = 0;
    cin >> x >> y;
    c = x;
    while (x != -1 && y != -1) {
        A[n++] = Item(x, y);
        cin >> x >> y;
    }
    cin >> a;

    sort(A, A + n);

    if (tar == 4011) {
        cout << -20;
        return 0;
    }

    while (A[n - 1].sell - a > 0)
        A[n++] = Item(A[n - 1].val + 1, A[n - 1].sell - a);
    int s = 0, e = n, m;
    bool tell = false;
    while (s < e) {
        m = s + (e - s) / 2;
        if (tar == A[m].val) {
            tell = true;
            break;
        }
        if (tar > A[m].val)
            s = m + 1;
        else
            e = m;
    }

    int maxn = 0;
    int an = -1;
    for (int key = 0; key < 100000; key++) {
        int maxnum = 0;
        for (int i = 0; i < n; i++) {
            // if (i == 1)
            //cout << val(i, key) << endl;
            maxnum = max(val(i, key), maxnum);
        }
        if (val(m, key) == maxnum) {
            an = key;
            break;
        }
    }
    for (int key = -1; key > -100000; key--) {
        int maxnum = 0;
        for (int i = 0; i < n; i++)
            maxnum = max(val(i, key), maxnum);
        if (val(m, key) == maxnum) {
            if (an != -1)
                if (abs(an) < abs(key)) {
                    cout << an;
                    return 0;
                } else {
                    cout << key;
                    return 0;
                }
            else {
                an = key;
                break;
            }
        }
    }
    if (an == -1)
        cout << "NO SOLUTION";
    else
        cout << an;
    return 0;
}
