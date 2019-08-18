#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    string num;
    stack<char> stk;
    int key = 0;
    cin >> num;
    if (num[0] == '-') {
	cout << '-';
	key++;
    }
    for (; key < num.size(); key++)
	stk.push(num[key]);

    while (stk.top() == '0')
	stk.pop();

    while (!stk.empty()) {
	cout << stk.top();
	stk.pop();
    }
}
