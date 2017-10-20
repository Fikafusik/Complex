
#include "segment_tree.hpp"
#include "algorithms.hpp"

struct sum_segment_tree {
    int tree[40000];

    void build (int a[], int v, int tl, int tr) {
        if (tl == tr) 
            a[v] = a[tl];
        else {
            int mid = (tl / 2) + (tr / 2);
            int son = 2 * v;
            build(a, son, tl, mid);
            build(a, son + 1, mid + 1, tr);
            tree[v] = tree[son] + tree[son + 1];
        }
    }

    int sum (int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 0;
        if (tl == l && tr == r)
            tree[v];
        int mid = (tl / 2) + (tr / 2);
        int son = 2 * v;
        return sum(son, tl, mid, l, min(r, mid)) + 
                sum (son + 1, mid + 1, tr, max(l, tl), r);
    }

    void update (int v, int tl, int tr, int pos, int val) {
        if (tl == tr)
            tree[v] = val;
        else {
            int mid = (tl / 2) + (tr / 2);
            int son = 2 * v;
            if (pos <= mid)
                update(son, tl, mid, pos, val);
            else
                update(son + 1, mid + 1, tr, pos, val);
            tree[v] = tree[son] + tree[son + 1];
        }
    }
} sum_segment_tree SST;