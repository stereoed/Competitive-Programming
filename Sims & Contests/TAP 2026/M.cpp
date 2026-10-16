#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

struct LazySegTree {
    struct Node {
        long long cap = 0;
        long long free = 0;
    };

    struct Tag {
        bool has_full = false;
        bool has_set = false;
        long long set = 0;
        long long add = 0;
    };

    const Tag no_tag = {false, false, 0, 0};
    const Node neutral = {0};

    Node merge(Node a, Node b){
        return {a.cap + b.cap, a.free + b.free};
    }
    
    Tag compose(Tag older, Tag newer){
        if (newer.has_full || newer.has_set) return newer;
        return {older.has_full, older.has_set, older.set, older.add + newer.add};
    }

    int n;
    vector<Node> tree;
    vector<Tag> lazy;

    LazySegTree(vector<long long> &A){
        n = A.size();
        tree.assign(4 * n, neutral);
        lazy.assign(4 * n, no_tag);
        build(A, 1, 0, n - 1);
    }

    void build(vector<long long> &A, int k, int l, int r){
        if (l == r){
            tree[k] = {A[l], A[l]};
            return;
        }
        int m = (l + r) / 2;
        build(A, 2 * k, l, m);
        build(A, 2 * k + 1, m + 1, r);
        tree[k] = merge(tree[2 * k], tree[2 * k + 1]);
    }

    void apply(int k, int len, Tag t){
        if (t.has_full) tree[k].free = tree[k].cap;
        if (t.has_set) tree[k].free = {t.set * len};
        tree[k].free += t.add * len;
        lazy[k] = compose(lazy[k], t);
    }

    void push(int k, int l, int m, int r){
        if (!lazy[k].has_full && !lazy[k].has_set && lazy[k].add == 0) return;
        apply(2 * k, m - l + 1, lazy[k]);
        apply(2 * k + 1, r - m, lazy[k]);
        lazy[k] = no_tag;
    }

    void update(int ql, int qr, Tag t, int k, int l, int r){
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr){
            apply(k, r - l + 1, t);
            return;
        }
        int m = (l + r) / 2;
        push(k, l, m, r);
        update(ql, qr, t, 2 * k, l, m);
        update(ql, qr, t, 2 * k + 1, m + 1, r);
        tree[k] = merge(tree[2 * k], tree[2 * k + 1]);
    }

    Node query(int ql, int qr, int k, int l, int r){
        if (qr < l || r < ql) return neutral;
        if (ql <= l && r <= qr) return tree[k];
        int m = (l + r) / 2;
        push(k, l, m, r);
        return merge(query(ql, qr, 2 * k, l, m), query(ql, qr, 2 * k + 1, m + 1, r));
    }

    void set_full(int l, int r){ update(l, r, {1, 0, 0, 0}, 1, 0, n - 1); } // assign val on [l, r]
    void assign(int l, int r, long long val){ update(l, r, {0, 1, val, 0}, 1, 0, n - 1); } // assign val on [l, r]
    void update(int l, int r, long long val){ update(l, r, {0, 0, 0, val}, 1, 0, n - 1); } // add val on [l, r]
    Node query(int l, int r){ return query(l, r, 1, 0, n - 1); } // inclusive [l, r], 0-indexed
};

void solve(){
    int N, M; cin >> N >> M;
    vector<long long> CAP(N + 1, 1e18);
    for (int i = 1; i <= N; i++) cin >> CAP[i];
    LazySegTree LST(CAP);
    dump(LST.query(0, N).free);

    for (int i = 0; i < M; i++){
        int k, a, b; cin >> k >> a >> b;

        if (k == 1){
            int l = 0, r = a + 1;
            while (l < r){
                int mid = l + (r - l) / 2;
                if (LST.query(mid, a).free <= b) r = mid;
                else l = mid + 1;
            }

            LST.update(l - 1, l - 1, - b + LST.query(l, a).free);
            LST.assign(l, a, 0);
            continue;
        }

        if (k == 2){
            cout << LST.query(a, b).cap - LST.query(a, b).free << '\n';
            LST.set_full(a, b);
            continue;
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
}