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
 
    int n; cin >> n;
	ll ob = n*(n+1)/2;
	
	if (ob&1){
	    cout << 0 << el;
	    return 0;
	}
	ob /= 2;
	
	vector<ll> dp(ob + 1);
	dp[0] = 1;
	
    for (int x = 1; x < n; x++) {
        for (int j = ob; j >= x; j--) {
            dp[j] += dp[j - x];
            dp[j] %= MOD;
        }
    }
	
	cout << dp[ob] << el;
}