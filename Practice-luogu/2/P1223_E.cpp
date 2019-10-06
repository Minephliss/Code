#include <iostream>
#include <iomanip>
#include <queue>
using namespace std;

struct Person
{
	int no;
	float cost;
	Person (int a = 0, float b = 0) {no = a; cost = b;}
	bool operator<(const Person & a) const
	{
		return cost > a.cost;
	}
};

priority_queue<Person> que;

int n;
float temp, aver;

int main()
{
	float x;
	Person last(0, 0.0);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> x;
		que.push(Person(i, x));
	}
	
	while(!que.empty())
	{
		cout << que.top().no << ' ';
		temp += last.cost;
		last = que.top();
		aver += temp;
		que.pop();
	}
	
	aver /= n;

	cout << endl << fixed << setprecision(2) << aver;

	return 0;
}
