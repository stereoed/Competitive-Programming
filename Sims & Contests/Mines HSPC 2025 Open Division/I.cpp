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
  int n;
  cin >> n;
  unordered_map<string, pii> m;
  rep(i, n){
    string s;
    int a, b;
    cin >> s >> a >> b;
    m[s] = {a, b};
  }

  int o = 0, la = -100000, lb = -100000;
  rep(i, n){
    string s;
    cin >> s;
    if (la == lb && la == -100000){
      la = m[s].first;
      lb = m[s].second;
    }

    o += abs(m[s].first - la) + abs(m[s].second - lb);
    la = m[s].first;
    lb = m[s].second;
  }
  cout << o;
}


int main() {
  FastIO;
  int t = 1;
  //cin >> t;
  while (t--) solve();
  return 0;
}