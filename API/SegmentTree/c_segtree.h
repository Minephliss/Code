#include <iostream>
using namespace std;

#ifndef SEGTREE
#define SEGTREE

#define maxn 100010
#define lef rt << 1
#define rig rt << 1 | 1
#define lefs l, mid, rt << 1
#define rigs mid + 1, r, rt << 1 | 1

typedef int Item;

class SegmentTree {
private:
    Item *sum, lazy;

public:
    SegmentTree(const Item l = 1, const Item r = maxn, const Item rt = 1);
    ~SegmentTree();
    SegmentTree::SegmentTree();
    void Update();
    void modify(const Item l, const Item r, const Item rt, const Item val);
    void put_lazy(const Item l, const Item r, const Item rt, const Item val);
    void push_lazy(const Item l, const Item r, const Item rt);
    Item ask(const Item l, const Item r, const Item rt);

    friend ostream& operator<<(ostream& os, const SegmentTree& seg);
    friend istream& operator>>(istream& is, SegmentTree& seg);
};

#endif
