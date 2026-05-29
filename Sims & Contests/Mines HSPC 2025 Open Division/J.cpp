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
  int l, a;
  cin >> l >> a;
  bool possible = true;
  int v = 0;
  rep(i, l + 1){
    int h;
    cin >> h;
    if (h - v > a) possible = false;
    v = h;
  }

  if (possible){
    cout << "POSSIBLE";
    return;
  }
  cout << "BUG REPORT";
}


int main() {
  FastIO;
  int t = 1;
  //cin >> t;
  while (t--) solve();
  return 0;
}