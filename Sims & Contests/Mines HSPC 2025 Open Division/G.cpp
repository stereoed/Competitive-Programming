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
typedef tuple<int, int, int> tiii;

void solve() {
  int n, c;
  cin >> n >> c;
  unordered_map<int, int> m;
  rep(i, n){
    int h, s;
    cin >> h >> s;
    auto it = m.find(h);
    if (it == m.end()) {
      m[h] = s;
    } else {
      it->second = min(it->second, s);
    }
  }

  vector<pii> values(24);
  rep(i, 24) values[i] = {(m.contains(i)) ? m[i] : 0, i};
  sort(all(values));

  int o = 0;
  int i = 0;
  int ma = 0;

  while (o <= c && i < 24){
    if (m.contains(values[i].second)){
      if (values[i].first + o > c) break;
      ma++;
      o += values[i].first;
    }
    i++;
  }

  cout << ma << el;

}


int main() {
  FastIO;
  int t = 1;
  //cin >> t;
  while (t--) solve();
  return 0;
}