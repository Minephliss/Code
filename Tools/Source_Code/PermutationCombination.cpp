#include <iostream>
using namespace std;

int main()
{
    char op;
    int down, up;
    bool con = true;
    while (con) {
        cin >> op;
        if(op == 'Q')
            break;
        cin >> down >> up;
        switch (op) {
        case 'A': {
            long long ans = 1;
            while (up--)
                ans = ans * down--;
            cout << ans << endl;
            break;
        }
        case 'C': {
            float mid = down / 2;
            int u = 1, d = 1;
            if (up > mid)
                up = down - up;
            for (int i = 1; i <= up; ++i) {
                d *= i;
                u *= down--;
            }
            cout << u / d << endl;
            break;
        }
        default: {
            cout << "Input C for conbination, A for Permutation, Q to quit." << endl;
        }
        }
    }

    return 0;
}
