#include "c_hpc.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string oper;
    HPC x, y;
    cin >> x >> oper >> y;
    if(oper == "+") cout << x + y;

    if(oper == "==") cout << (x == y);
    if(oper == "!=") cout << (x != y);
    if(oper == ">") cout << (x > y);
    if(oper == "<") cout << (x < y);
    if(oper == ">=") cout << (x >= y);
    if(oper == "<=") cout << (x <= y);
}
