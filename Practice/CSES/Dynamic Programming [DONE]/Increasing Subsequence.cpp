#pragma GCC optimize("Ofast")
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
#define repb(i, n) for (int i = (int)n - 1; i >= 0; i--)
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define ms(arr, val) memset(arr, val, sizeof(arr))
 
const int MOD = 1e9 + 7;
const ll INF = 1e18;
 
void solve() {
	int n, aux; cin >> n;
	vi v(n + 1, MOD);
	
	rep(i, n){
		cin >> aux;
		auto it = lower_bound(all(v), aux);
		*it = aux;
	}
	
	rep(i, n + 1){
		if (v[i] == MOD){
			cout << i << el;
			return;
		}
	}
}
 
int main() {
    FastIO;
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}