#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define repk(i, k, n) for (ll i = (ll)(k); i < (ll)(n); ++i)
#define all(v) (v).begin(), (v).end()

void solve() {
    ll n; cin >> n;
    vector<ll> seq(n); rep(i, n) cin >> seq[i];
    sort(seq.begin(), seq.end());    

    ll ans = 0;

    rep(i, n){
/*         ll l = i, r = n - 1;
        ll mid; */
        
        auto it = upper_bound(seq.begin(), seq.end(), seq[i] + 2);
        it--;

        ll l = it - seq.begin();

/*         while(l < r){
            mid = l + (r - l + 1) / 2;

            if (seq[mid] - seq[i] <= 2) l = mid;
            else r = mid - 1;
        }
*/
        
        ll delta = l - i;
        ans += (delta * (delta - 1)) / 2; 

    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}