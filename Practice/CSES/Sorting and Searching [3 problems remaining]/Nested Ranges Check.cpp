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
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define el '\n'
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repx(i, a, n) for (int i = (int)a; i < (int)(n); i++)
#define repb(i, n) for (int i = n - 1; i >= 0; i--)
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define ms(arr, val) memset(arr, val, sizeof(arr))
 
 
struct node{
	int idx;
	int f, s;
};
 
struct SegTree {
    using Agg = pair<int,int>; // {max_s, min_s}
 
    int n = 0, sz = 1;
    vector<Agg> st;
 
    static constexpr int NEG_INF = numeric_limits<int>::lowest();
    static constexpr int POS_INF = numeric_limits<int>::max();
    Agg NEUT = {NEG_INF, POS_INF};
 
    static Agg merge_agg(const Agg& a, const Agg& b) {
        return { max(a.first, b.first),  // max_s
                 min(a.second, b.second) // min_s
               };
    }
 
    void init(int n_) {
        n = n_;
        sz = 1;
        while (sz < n) sz <<= 1;
        st.assign(2 * sz, NEUT);
    }
 
    void build(const vector<node>& a) {
        init((int)a.size());
        for (int i = 0; i < n; i++) st[sz + i] = {a[i].s, a[i].s};
        for (int i = sz - 1; i >= 1; i--) st[i] = merge_agg(st[2*i], st[2*i+1]);
    }
 
    // update position pos with a new node (uses its s)
    void set_point(int pos, const node& val) {
        int p = sz + pos;
        st[p] = {val.s, val.s};
        for (p >>= 1; p >= 1; p >>= 1) st[p] = merge_agg(st[2*p], st[2*p+1]);
    }
 
    // returns {max_s, min_s} on [l, r] inclusive
    Agg query(int l, int r) const {
        if (l > r) return NEUT;
        l += sz; r += sz;
        Agg left = NEUT, right = NEUT;
        while (l <= r) {
            if (l & 1) left = merge_agg(left, st[l++]);
            if (!(r & 1)) right = merge_agg(st[r--], right);
            l >>= 1; r >>= 1;
        }
        return merge_agg(left, right);
    }
 
    int query_max_s(int l, int r) const { return query(l, r).first; }
    int query_min_s(int l, int r) const { return query(l, r).second; }
};
 
void solve(){
	int n; cin >> n;
	vector<node> arr(n); rep(i, n){ arr[i].idx = i; cin >> arr[i].f; cin >> arr[i].s; }
	
	// Se ordena asc el abre wea, y desc el cierra wea.
	sort(all(arr), [](const node &a, const node &b){
		if (a.f != b.f)
            return a.f < b.f;
        return a.s > b.s;
	});
	
	SegTree st;
	st.build(arr);
	
	// Contained
	vector<bool> contained(n, false);
	rep(i, n){
		contained[arr[i].idx] = st.query_min_s(i + 1, n - 1) <= arr[i].s;
	}
	
	// Contains
	vector<bool> contains(n, false);
	rep(i, n){
		contains[arr[i].idx] = st.query_max_s(0, i - 1) >= arr[i].s;
	}
	
	rep(i, n){
		cout << (contained[i] ? 1 : 0) << " ";
	}
	cout << el;
	
	rep(i, n){
		cout << (contains[i] ? 1 : 0) << " ";
	}
	cout << el;
}
 
int main() {
    FastIO;
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}