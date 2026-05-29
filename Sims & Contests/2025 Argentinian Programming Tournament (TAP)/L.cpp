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

ll n, g;
vector<ll> prices;
ll mat[MAXN][500];

ll dp(int idx, int bp){
  if (idx == n) return 0;
  if (mat[idx][bp] != -1) return mat[idx][bp];

  mat[idx][bp] = dp(idx + 1, bp);
  //debug(idx + bp - 1);
  //debug(idx - 1);
  if (idx + bp <= n){
    //cout << "calc, slang for calculator" << el;
    mat[idx][bp] = max({
        mat[idx][bp],
        dp(idx + bp, bp + 1) + g - prices[idx + bp - 1] + (idx >= 1 ? prices[idx - 1] : 0)
        // Con prices me tira error
        });
  }
  return mat[idx][bp];
}

void solve(){
  cin >> n >> g;
  prices = vector<ll>(n); rep(i, n) cin >> prices[i];
  repx(i, 1, n) prices[i] += prices[i-1]; // prefix sum
  ms(mat, -1);

  ///debug(n);
  
  cout << dp(0, 1) << el;
}

int main(){
  FastIO;
  int t = 1;
  //cin >> t;
  while (t--) solve();
}
