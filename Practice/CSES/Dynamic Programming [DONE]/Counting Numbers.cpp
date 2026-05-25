#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define el '\n'
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repx(i, a, n) for (int i = (int)a; i < (int)(n); i++)
#define repb(i, n) for (int i = (int)n - 1; i >= 0; i--)
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define ms(arr, val) memset(arr, val, sizeof(arr))
 
const int MOD = 1e9 + 7;
const int INF = 1e9;
 
vector<ll> p9, p10;
 
/*
 CSES DP Counting numbers.
 Cuantos numeros de 0 a X hay que no tengan dos numeros iguales seguidos?
*/
 
// Amount from 10^(i-1) ... 10^ivector<ll> p9, p10;
 
inline void precomp() {
    p9 = vector<ll>(20, 1);
    p10 = vector<ll>(20, 1);
	
    repx(i, 1, 19) {
        p9[i] = p9[i - 1] * 9;
        p10[i] = p10[i - 1] * 10;
    }
}
 
inline ll tail(ll num, int rem, int prev) {
    if (rem == 0) return 1;
 
    ll unit = p10[rem - 1];
    int cur = num / unit;
 
    ll ans = (cur - (prev < cur)) * p9[rem - 1];
 
    if (cur == prev) return ans;
    return ans + tail(num % unit, rem - 1, cur);
}
 
inline ll fresh(ll num) {
    if (num < 10) return num + 1;
 
    int len = to_string(num).size();
    ll ans = 1;
 
    repx(d, 1, len) ans += p9[d];
 
    ll unit = p10[len - 1];
    int cur = num / unit;
 
    ans += 1LL * (cur - 1) * p9[len - 1];
    return ans + tail(num % unit, len - 1, cur);
}
 
void solve() {
    ll a, b;
    cin >> a >> b;
    precomp();
    cout << fresh(b) - fresh(a - 1) << el;
}
 
int main() {
	FastIO;
	int t = 1;
	while (t--) solve();
	return 0;
}