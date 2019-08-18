#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int N;
    int ans[1001], an[1001], top = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> ans[i];

    sort(ans, ans + N);
    for (int i = 0; i < N; i++) {
        if (i == 0 || ans[i] != ans[i - 1])
            an[top++] = ans[i];
    }

    cout << top << endl;
    for (int i = 0; i < top; i++)
        cout << an[i] << ' ';
}
