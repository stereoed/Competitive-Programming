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
    FastIO;
	
	// Initialization
    int n, m; cin >> n >> m;
    vi arr(n); rep(i,n) cin >> arr[i];
	vector<ll> ans(m + 1, 0);
	
	// We must star the dp accordingly on the first val
	if (arr[0] == 0) { fill(all(ans), 1);  ans[0] = 0; }
	else ans[arr[0]] = 1;
	
	// Auxiliary variables for copying later
	vector<ll> ans_aux(m + 1, 0);
	ll aux = 0;
	
	// Loop
	repx(i, 1, n){
		int& val = arr[i];
		
		// Fixed value;
		if (val != 0){
			// Possible solutions, cleanease the array, save it
			aux = ans[val];
			if (val > 1) aux += ans[val-1];
			if (val < m) aux += ans[val+1];
			aux %= MOD;
			
			fill(all(ans), 0);
			
			ans[val] = aux;
			continue;
		}
		
		// Non-fixed value;
		ans_aux = ans; // o(m) copy
		repx(j, 1, m + 1){
			if (j > 1) ans[j] += ans_aux[j-1];
			if (j < m) ans[j] += ans_aux[j+1];
			
			ans[j] %= MOD;
		}
	}
	
	ll o = 0;
    rep(i, m + 1) o = (o + ans[i]) % MOD;
	
	cout << o << el;
}