#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define el '\n'
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repx(i, a, n) for (int i = (int)a; i < (int)(n); i++)
#define pb push_back
#define all(v) v.begin(), v.end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
using T3 = tuple<long long, long long, int>;

void solve() {
    int n; cin >> n;
    vector<T3> ev;
    ev.reserve(2*n);

    rep(i,n){
      long long x,a,b; cin >> x >> a >> b;
      ev.push_back({a, x, 1});
      ev.push_back({b, x, -1});
    }

    sort(all(ev), [](const T3& l, const T3& r){
        const auto& [h1, x1, t1] = l;
        const auto& [h2, x2, t2] = r;
        __int128 lhs = (__int128)h1 * x2;
        __int128 rhs = (__int128)h2 * x1;
        if (lhs != rhs) return lhs < rhs;   // compare slopes h/x
        return t1 > t2;                     // openings (+1) before closings (-1)
    });

    int cur = 0, best = 0;
    for (const auto &[__, ____, mod] : ev){
      cur += mod;
      best = max(best, cur);
    }
    cout << best << el;
}

int main() {
  FastIO;
  int t = 1;
  //cin >> t;
  while (t--) solve();
  return 0;
}