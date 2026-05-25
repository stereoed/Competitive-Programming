#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define el '\n'
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repx(i, a, n) for (int i = (int)a; i < (int)(n); i++)
#define repb(i, n) for (int i = n - 1; i >= 0; i--)
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define ms(arr, val) memset(arr, val, sizeof(arr))
 
const int MOD = 1e9 + 7;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, m; cin >> n >> m;
	
	vi a(n), b(m), o;
	rep (i, n) cin >> a[i];
	rep (i, m) cin >> b[i];
	
	vvi dp(n + 1, vi(m + 1, 0));
	repb(i, n) repb(j, m) {
    	if (a[i] == b[j]) dp[i][j] = 1 + dp[i + 1][j + 1];
    	else dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
	}
	
	int i = 0, j = 0;
    while(i < n && j < m){
        if(a[i] == b[j]){
            o.pb(a[i]);
            i++, j++;
        }
        else if(dp[i + 1][j] >= dp[i][j + 1]) i++;
        else j++;
    }
	
	cout << dp[0][0] << el;
	rep(i, dp[0][0]) cout << o[i] << " ";
}