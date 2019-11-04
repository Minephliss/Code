#ifndef HPC_
#define HPC_

#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 1000;

class HPC {
private:
    int len;
    bool minus;
    char bign[maxn];

public:
    HPC();
    HPC(char* strs, int len, bool minus);

    void rbign(char* strs) const;
    int rlen() const;
    bool rminus() const;

    bool operator<(const HPC& a) const;
    bool operator>(const HPC& a) const;
    bool operator<=(const HPC& a) const;
    bool operator>=(const HPC& a) const;
    bool operator==(const HPC& a) const;
    bool operator!=(const HPC& a) const;

    HPC operator+(const HPC& a) const;
    HPC operator-(const HPC& a);
    HPC operator*(const HPC& a);
    HPC operator/(const HPC& a);
    HPC operator%(const HPC& a);
    HPC operator%(const int& a);
    HPC operator=(const HPC& a);

    friend istream& operator>>(istream& is, HPC& a);
    friend ostream& operator<<(ostream& os, const HPC& a);
};

#endif
