#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <set>
#include <cmath>
#include <string.h>
 
// PBDS
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define el '\n'
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repx(i, a, n) for (int i = (int)a; i < (int)(n); i++)
#define repb(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define ms(arr, val) memset(arr, val, sizeof(arr))
 
struct node{
    int idx, f, s;
};
 
// ordered multiset via (value, unique_id)
template<class Key>
using ordered_set = tree<Key, null_type, less<Key>, rb_tree_tag, tree_order_statistics_node_update>;
 
struct OrderedMultiSet {
    ordered_set<pair<int,int>> t;
    int uid = 0;
 
    void clear(){ t.clear(); uid = 0; }
    int size() const { return (int)t.size(); }
    void insert_value(int x){ t.insert({x, uid++}); }
 
    // #values <= x
    int count_le(int x) const { return (int)t.order_of_key({x, INT_MAX}); }
    // #values < x
    int count_lt(int x) const { return (int)t.order_of_key({x, INT_MIN}); }
    // #values >= x
    int count_ge(int x) const { return size() - count_lt(x); }
    // #values > x
    int count_gt(int x) const { return size() - count_le(x); }
};
 
vi contains, contained;
 
void ans(const vector<node>& arr){
    OrderedMultiSet seen;
 
    // contains: how many seen with s <= current s (matches your distance(begin, upper_bound(s)))
    for (int i = (int)arr.size() - 1; i >= 0; --i){
        auto [idx, f, s] = arr[i];
        contains[idx] = seen.count_le(s);
        seen.insert_value(s);
    }
 
    // contained: how many seen with s >= current s (your code was lower_bound(s-1)->end, i.e. >= s-1; likely intended >= s)
    seen.clear();
    for (int i = 0; i < (int)arr.size(); ++i){
        auto [idx, f, s] = arr[i];
        contained[idx] = seen.count_ge(s);
        seen.insert_value(s);
    }
}
 
void solve(){
    int n; cin >> n;
    vector<node> arr(n);
    rep(i, n){
        arr[i].idx = i;
        cin >> arr[i].f >> arr[i].s;
    }
    contains.assign(n, 0);
    contained.assign(n, 0);
 
    sort(all(arr), [](const node &a, const node &b){
        if (a.f != b.f) return a.f < b.f;
        return a.s > b.s;
    });
 
    ans(arr);
 
    rep(i, n) cout << contains[i] << " ";
    cout << el;
    rep(i, n) cout << contained[i] << " ";
    cout << el;
}
 
int main() {
    FastIO;
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}