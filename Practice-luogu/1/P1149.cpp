#include <iostream>
#include <vector>
using namespace std;

int n, cnt;
const int nums[] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };

void solve();
void judge();

int main()
{
    cin >> n;

    n -= 4;

    solve();

    cout << cnt;

    return 0;
}

void solve()
{
    //	get_combine(n);
    judge();
}

int getnum(int num)
{
    int ans = 0;
    if (num == 0)
	return nums[0];
    while (num > 0) {
	ans += nums[num % 10];
	num /= 10;
    }
    return ans;
}
/*
void get_combine(int lefts)
{
	if(lefts >= 2)
	{
		for(int i = 0; i < 10; i++)
		{
			if(lefts >= nums[i])
			{
				combine.push(i);
				get_combine(lefts - nums[i]);
				combine.pop();
			}
		}
	}
	else if(lefts == 0)
	{

		stack<int> te_use = combine;
		int use_[te_use.size()];		int i = 0;

		while(!te_use.empty())
		{
			use_[i++] = te_use.top();
			te_use.pop();
		}

		if(judge(use_, i))
			cnt++;
	}
}
*/
void judge()
{
    for (int i = 0; i < 1999; i++)
	for (int j = 0; j < 1999; j++)
	    if (getnum(i) + getnum(j) + getnum(i + j) == n) {
		cout << i << ' ' << j << ' ' << i + j << endl;
		cout << getnum(i) << endl;
		cnt++;
	    }
}
