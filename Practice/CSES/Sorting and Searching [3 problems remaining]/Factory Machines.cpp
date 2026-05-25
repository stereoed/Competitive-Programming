#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <set>
#include <cmath>
#include <string.h>
 
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
 
 
ll n, t;
vi machines;
 
bool ok(ll k){
	ll sum = 0;
	//cout << "mid: " << k << el;
	rep(i, n) {sum += k / machines[i]; if (sum < 0) return true;};
	//cout << "sum: " << sum << el;
	return sum >= t;
}
 
void solve(){
	cin >> n >> t;
	machines = vi(n); rep(i, n) cin >> machines[i];
	sort(all(machines));
	
	ll l{0}, r{(ll)1e18};
	while (l < r){
	    //cout << l << " " << r << el;
		ll mid = l + (r - l)/2;
		if (ok(mid)) r = mid - 1;
		else l = mid + 1;
	}
	cout << (ok(l) ? l : l + 1) << el;
}
 
int main() {
    FastIO;
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}