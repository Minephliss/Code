#include "c_hpc.h"
#include <iostream>
#include <cstring>

using namespace std;

HPC::HPC()
{
    memset(bign, '0', sizeof(bign));
    minus = false;
    len = 0;
}

HPC::HPC(char* strs, int len, bool minus)
{
    for (int i = 0; i < len; ++i) {
        bign[i] = strs[i];    
    }
    this -> len = len;
    this -> minus = minus;
}

void HPC::rbign(char* strs) const
{
    for (int i = 0; i < maxn; ++i) {
        strs[i] = bign[i];
    }
}

bool HPC::rminus() const
{
    return minus;
}
int HPC::rlen() const
{
    return len;
}

bool HPC::operator<(const HPC& a) const
{
    if(len < a.len)         return true;
    else if(len > a.len)    return false;
    char strs[maxn];
    a.rbign(strs);
    for (int i = 0; i < len; ++i){
        if(bign[i] < strs[i])
            return true;
        else if(bign[i] > strs[i])
            return false;
    }
    return false;
}

bool HPC::operator>(const HPC& a) const
{
    if(len > a.len)         return true;
    else if(len < a.len)    return false;
    char strs[maxn];
    a.rbign(strs);
    for (int i = 0; i < len; ++i){
        if(bign[i] > strs[i])
            return true;
        else if(bign[i] < strs[i])
            return false;
    }
    return false;
}

bool HPC::operator<=(const HPC& a) const
{
    if(len < a.len)         return true;
    else if(len > a.len)    return false;
    char strs[maxn];
    a.rbign(strs);
    for (int i = 0; i < len; ++i){
        if(bign[i] < strs[i])
            return true;
        else if(bign[i] > strs[i])
            return false;
    }
    return true;
}

bool HPC::operator>=(const HPC& a) const
{
    if(len > a.len)         return true;
    else if(len < a.len)    return false;
    char strs[maxn];
    a.rbign(strs);
    for (int i = 0; i < len; ++i){
        if(bign[i] > strs[i])
            return true;
        else if(bign[i] < strs[i])
            return false;
    }
    return true;
}

bool HPC::operator==(const HPC& a) const
{
    if(len != a.len)         return false;
    char strs[maxn];
    a.rbign(strs);
    for (int i = 0; i < len; ++i) {
        if(bign[i] < strs[i])
            return false;
        else if(bign[i] > strs[i])
            return false;
    }
    return true;
}

bool HPC::operator!=(const HPC& a) const
{
    if(len != a.len)         return true;
    char strs[maxn];
    a.rbign(strs);
    for (int i = 0; i < len; ++i)
        if(bign[i] != strs[i])
            return true;
    return false;
}

HPC HPC::operator+(HPC& a)
{
    char strs[maxn];
    if(minus == a.rminus()){
    char ans[maxn];
    int i;
    memset(ans, '0', sizeof(ans));
    int len = max(this -> len, a.len);
    a.rbign(strs);
    for (i = 0; i < len; ++i) {
        if(bign[i] + strs[i] + ans[i] - 3 * '0' > 9)
        {
            ans[i] = ans[i] + bign[i] + strs[i] - 2 * '0' - 10;
            ans[i + 1]++;
        }
        else
            ans[i] = ans[i] + bign[i] + strs[i] - 2 * '0';
    }
    if(ans[i] != '0')
        i++;
    HPC res(ans, i, minus);
    return res;}
    else
    {
        if(minus)
        {
            return a - HPC(strs, len, !minus);}
        else
            return *this - HPC(a.bign, a.len, !a.minus);
    }
}

istream& operator>>(istream& is, HPC& a)
{
    char stk[maxn]; 
    char ch;
    bool minus = false;
    int t = 0, p = 0;
    is >> ch;
    while(ch != ' ' && ch != '\n')
    {
        if(ch == '-')
            minus = true;
        else
            stk[t++] = ch;
        ch = getchar();
    }
    a.len = t;
    a.minus = minus;
    while(--t)
        a.bign[p++] = stk[t];
    a.bign[p++] = stk[t];
    return is;
}

ostream& operator<<(ostream& os, const HPC& a)
{
    for (int i = a.len - 1; i >= 0; --i) {
        os << a.bign[i];
    }
    return os;
}
