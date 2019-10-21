#include "c_segtree.h"
#include <iostream>
using namespace std;

SegmentTree::SegmentTree(const Item l = 1, const Item r = maxn, const Item rt = 1)
{
    //==========================EDITING==============================
    Build(l, r, rt);
}

SegmentTree::~SegmentTree()
{
}
SegmentTree::Build(const Item l, const Item r, const Item rt)
{
    if (l == r)
        cin >> sum[rt];
    else {
        int mid = (l + r) >> 1;
        build(lefs), build(rigs);
        Update(rt);
    }
}
