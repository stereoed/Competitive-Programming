#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <set>
#include <cmath>
#include <string.h>
#include <queue>
 
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// *set.find_by_order(X) [Element at position X], set.order_of_key(x) [N smaller than X]
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define el '\n'
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repx(i, a, n) for (int i = (int)a; i < (int)(n); i++)
#define repb(i, n) for (int i = n - 1; i >= 0; i--)
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define ms(arr, val) memset(arr, val, sizeof(arr))
 
 
ll n, k;
 
bool ok(const vector<ll>& a, ll M, ll k) {
    ll parts = 1;
    ll cur = 0;
    for (ll v : a) {
        if (v > M) return false;
        if (cur + v > M) {
            parts++;
            cur = 0;
        }
        cur += v;
    }
    return parts <= k;
}
 
void solve() {
    cin >> n >> k;
    vector<ll> a(n);
    ll lo = 0, hi = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        hi += a[i];
        lo = max(lo, a[i]);
    }
 
    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        if (ok(a, mid, k)) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << "\n";
}
 
 
int main() {
    FastIO;
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}