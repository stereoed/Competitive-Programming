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
 
 
ll n, a, b;
vector<ll> arr, sums;
 
struct SegTreeMin {
    int n;                 // size rounded to power of 2
    long long INF = (1LL<<62);
    vector<long long> t;   // 1-indexed tree
 
    SegTreeMin(int sz = 0) { init(sz); }
 
    void init(int sz) {
        n = 1;
        while (n < sz) n <<= 1;
        t.assign(2 * n, INF);
    }
 
    void build(const vector<long long>& a) {
        init((int)a.size());
        for (int i = 0; i < (int)a.size(); i++) t[n + i] = a[i];
        for (int i = n - 1; i >= 1; i--) t[i] = min(t[2 * i], t[2 * i + 1]);
    }
 
    // set a[pos] = val
    void set_point(int pos, long long val) {
        int p = n + pos;
        t[p] = val;
        for (p >>= 1; p >= 1; p >>= 1) t[p] = min(t[2 * p], t[2 * p + 1]);
    }
 
    // min on [l, r] inclusive
    long long query(int l, int r) const {
        long long res = INF;
        int L = n + l, R = n + r;
        while (L <= R) {
            if (L & 1) res = min(res, t[L++]);
            if (!(R & 1)) res = min(res, t[R--]);
            L >>= 1; R >>= 1;
        }
        return res;
    }
};
 
 
void solve(){
	cin >> n >> a >> b;
	arr = vector<ll>(n); sums = vector<ll>(n + 1, 0);
	rep(i,n) { cin >> arr[i]; sums[i+1] += sums[i] + arr[i]; }
	
	ll ans = -1e18;
	SegTreeMin st;
	st.build(sums);
	
	rep(i, n){ // i represents the finish line
	    if (i - a + 1 >= 0)
		    ans = max(ans, sums[i+1] - st.query(max(0LL, i - b + 1), i - a + 1));
	}
	
	cout << ans << el;
	
}
 
int main() {
    FastIO;
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}