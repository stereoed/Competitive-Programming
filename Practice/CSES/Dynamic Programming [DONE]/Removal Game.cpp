#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<ll> vi;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ms(arr, val) memset(arr, val, sizeof(arr))
 
static ll dp[5005][5005];
 
ll dps(int a, int b, vector<ll>& v){
    if (a > b) return 0;
    if (dp[a][b] != -1) return dp[a][b];
 
    return dp[a][b] = max(
        v[a] - dps(a + 1, b, v),
        v[b] - dps(a, b - 1, v)
    );
}
 
int main() {
    FastIO;
 
    int n; cin >> n;
    vector<ll> v(n);
    
    ll s = 0;
    rep(i, n) cin >> v[i], s += v[i];
 
    ms(dp, -1);
    ll diff = dps(0, n - 1, v);
    cout << (s + diff) / 2 << '\n';
}