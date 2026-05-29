#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vi> vvi;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define el '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define ms(arr, val) memset(arr, val, sizeof(arr))
#define rep(i, n) for(int i = 0; i < n; i++)
#define repx(i, j, n) for(int i = j; i < n; i++)
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

const int INF = 1e9;
const ll LINF = 1e18;
const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

void solve(){
  int n; cin >> n;
  ll minx = INF, miny = INF, maxx = 0, maxy = 0;
  rep(i, n){
    ll x, y; cin >> x >> y;
    minx = min(minx, x);
    miny = min(miny, y);
    maxx = max(maxx, x);
    maxy = max(maxy, y);
  }

  cout << 2*(maxx-minx + 2) +  2*(maxy - miny + 2) << el;
}

int main(){
  FastIO;
  int t = 1;
  //cin >> t;
  while (t--) solve();
}
