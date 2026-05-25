#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <set>
#include <cmath>
#include <string.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define el '\n'
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repx(i, a, n) for (int i = (int)a; i < (int)(n); i++)
#define repb(i, n) for (int i = n - 1; i >= 0; i--)
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define ms(arr, val) memset(arr, val, sizeof(arr))
 
const int MAXN = 5 * 1e3 + 5;
const int MOD = 1e9 + 7;
 
void solve(){
    string a, b; cin >> a >> b;
 
    vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1));
    rep(i, a.size() + 1) dp[i][0] = i;
    rep(i, b.size() + 1) dp[0][i] = i;
 
    repx(i, 1, a.size() + 1){
        repx(j, 1, b.size() + 1){
            dp[i][j] = min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]}) + 1;
            if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
 
        }
    }
 
   cout << dp[a.size()][b.size()] << el;
}
 
int main() {
    FastIO;
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
 
 