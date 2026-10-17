#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define repk(i, k, n) for (ll i = (ll)(k); i < (ll)(n); ++i)
#define all(v) (v).begin(), (v).end()

struct Frac {
    ll p, q; 
    bool neg;
    bool operator<(const Frac& other) const {
        if (p != other.p) return p < other.p;
        if (q != other.q) return q < other.q;
        return neg < other.neg;
    }
};

void solve() {
    ll n; cin >> n;
    vector<ll> A(n), B(n);
    rep(i, n) cin >> A[i];
    
    ll glob = 0;
    map<Frac, ll> contar;

    ll maxi = 0;
    rep(i, n){
        cin >> B[i];
        ll d;
        if (A[i] == 0 && B[i] != 0) continue;
        else if (A[i] == 0 && B[i] == 0) glob++;
        else {
            ll p = abs(A[i]), q = abs(B[i]);
            ll g = gcd(p, q);
            bool neg = A[i] * B[i] < 0;
            p /= g; q /= g;
            Frac fraccion{p, q, neg};
            contar[fraccion]++;
            maxi = max(contar[fraccion], maxi);
        } 
    }

    cout << maxi + glob << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}