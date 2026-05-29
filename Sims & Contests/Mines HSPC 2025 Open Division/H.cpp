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
  int a, b, c;
  cin >> a >> b >> c;
  double final = (a * 0.25) + (b * 0.25) + (c * 0.5);
  cerr << final;
  if (final >= 90){
    cout << 'A';
    return;
  }
  if (final >= 80){
    cout << 'B';
    return;
  }
  if (final >= 70){
    cout << 'C';
    return;
  }
  if (final >= 60){
    cout << 'D';
    return;
  }
  cout << 'F';
}


int main() {
  FastIO;
  int t = 1;
  //cin >> t;
  while (t--) solve();
  return 0;
}