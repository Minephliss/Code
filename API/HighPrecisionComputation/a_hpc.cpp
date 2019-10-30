#include "c_hpc.h"
#include <iostream>

using namespace std;

HPC::HPC()
{
    memset(bign, '0', sizeof(bign));
    len = 0;
}

HPC::HPC(char* strs, int len)
{
    for (int i = 0; i < len; ++i) {
        bign[i] = strs[i];    
    }
    this -> len = len;
}

void HPC::rbign(char* strs) const
{
    for (int i = 0; i < maxn; ++i) {
        strs[i] = bign[i];
    }
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
    for (int i = len - 1; i >= 0; ++i) {
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
    for (int i = len - 1; i >= 0; ++i) {
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
    for (int i = len - 1; i >= 0; ++i) {
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
    for (int i = len - 1; i >= 0; ++i) {
        if(bign[i] > strs[i])
            return true;
        else if(bign[i] < strs[i])
            return false;
    }
    return true;
}

bool HPC::operator==(const HPC& a) const
{
    if(len < a.len)         return false;
    else if(len > a.len)    return false;
    char strs[maxn];
    a.rbign(strs);
    for (int i = len - 1; i >= 0; ++i) {
        if(bign[i] < strs[i])
            return false;
        else if(bign[i] > strs[i])
            return false;
    }
    return true;
}

bool HPC::operator!=(const HPC& a) const
{
    if(len > a.len)         return true;
    else if(len < a.len)    return true;
    char strs[maxn];
    a.rbign(strs);
    for (int i = len - 1; i >= 0; ++i) {
        if(bign[i] > strs[i])
            return true;
        else if(bign[i] < strs[i])
            return true;
    }
    return false;
}

HPC HPC::operator+(const HPC& a)
{
    char ans[maxn];
    char strs[maxn];
    int i;
    memset(ans, '0', sizeof(ans));
    int len = max(this -> len, a.rlen());
    a.rbign(strs);
    for (i = 0; i < len; ++i) {
        if(bign[i] + strs[i] - 2 * '0' > 9)
        {
            ans[i] = bign[i] + strs[i] - '0' - 10;
            ans[i + 1]++;
        }
        else
            ans[i] = bign[i] + strs[i] - '0';
    }
    if(ans[i] != '0')
        i++;
    HPC res(ans, i);
    return res;
}

istream& operator>>(istream& is, HPC& a)
{
    char stk[maxn]; 
    char ch;
    int t = 0, p = 0;
    is >> ch;
    while(ch != ' ' && ch != '\n')
    {
        stk[t++] = ch;
        ch = getchar();
    }
    a.len = t;
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