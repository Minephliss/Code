#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

bool mem[100000000], ju;
int data[20], cnt, n, k;
vector<int> sums;

void sum_(int re, int sum, int key);

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
	cin >> data[i];

    sum_(k, 0, 0);

    for (int i = 0; i < sums.size(); i++) {
	ju = true;
	if (!mem[sums[i]]) {
	    for (int j = 2; j < sqrt(sums[i]); j++) {
		int a1 = sums[i] / j;
		if (j * a1 == sums[i]) {
		    ju = false;
		    break;
		}
	    }
	    if (ju) {
		mem[sums[i]] = true;
		cnt++;
	    }
	} else
	    cnt++;
    }

    cout << cnt;

    return 0;
}

void sum_(int re, int sum, int key)
{
    if (re > 0)
	for (int i = key; i < n; i++)
	    sum_(re - 1, sum + data[i], i + 1);
    else
	sums.push_back(sum);
}
