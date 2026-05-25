#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <set>
#include <cmath>
#include <string.h>
using namespace std;
 
typedef long long ll;
#define el '\n'
 
template <class T, T merge(T, T)> struct ST{
    T sz = 1;
    const T LOCAL_INF = 1e18; 
    vector<T> arr;
 
    T clamp(T val) {return max((T)0, min(val, sz - 1));} 
 
    T build_tree_full(T pointer){
        if (pointer >= sz - 1) return arr[pointer];
        T child_a = build_tree_full(2 * pointer + 1);
        T child_b = build_tree_full(2 * pointer + 2);
 
        arr[pointer] = merge(child_a, child_b);
        return arr[pointer];
    }
 
    void streefy(vector<T>& v){
        while (sz < v.size()) sz <<= 1;
        arr.assign(2 * sz, 0LL);
        for (T i = 0; i < v.size(); i++) arr[sz - 1 + i] = v[i];
        build_tree_full(0);
    }
 
    T query(T l, T r) {return query(l, r, 0, 0, sz - 1);}
 
    T query(T l, T r, T node, T node_l, T node_r) {
        if (r < node_l || l > node_r) return 0; 
        if (l <= node_l && node_r <= r) return arr[node]; 
 
        T mid = (node_l + node_r) / 2;
        return merge(
                query(l, r, 2*node + 1, node_l, mid),
                query(l, r, 2*node + 2, mid + 1, node_r)
                );
    }
 
    void update(T idx, T val){
        idx = sz - 1 + clamp(idx);
        arr[idx] = val;
 
        while (idx > 0){
            idx = (idx - 1) / 2;
            arr[idx] = merge(arr[2 * idx + 1], arr[2 * idx + 2]);
        }
    }
};
 
ll sum(ll a, ll b){
    return a + b;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, k; 
    cin >> n >> k;
 
    vector<ll> arr(n, 1);
 
    ST<ll, sum> st;
    st.streefy(arr);
 
    int alive = n, pos = 0;
    while (alive){
        pos += k;
        pos %= alive;
 
        int left = 0, right = n - 1;
        while (left < right){
            int mid = left + (right - left)/2;
            if (st.query(0, mid) >= pos+1) right = mid;
            else left = mid + 1;
        }
 
        cout << left + 1 << el;
        st.update(left, 0);
        alive--;
    }
 
    return 0;
}