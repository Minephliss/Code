#include <cstring>
#include <iostream>
using namespace std;

int pri[20000];
bool is_pri[20000];

bool search(int* A, int s, int e, int key)
{
    int mid;
    while (s < e) {
	mid = s + (e - s) / 2;
	if (A[mid] == key)
	    return true;
	else if (A[mid] > key)
	    e = mid;
	else
	    s = mid + 1;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;

    int p = 0;
    memset(is_pri, true, sizeof(is_pri));

    is_pri[0] = false;
    is_pri[1] = false;

    for (int i = 2; i < n; i++)
	if (is_pri[i]) {
	    for (int j = 2 * i; j < n; j += i)
		is_pri[j] = false;
	    pri[p++] = i;
	}

    for (int d1 = 0; pri[d1] < n; d1++)
	for (int d2 = 0; pri[d2] + pri[d1] < n; d2++)
	    if (search(pri, 0, p, n - pri[d1] - pri[d2])) {
		cout << pri[d1] << ' ' << pri[d2] << ' ' << n - pri[d1] - pri[d2];
		return 0;
	    }
}
