#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<vb> vvb;

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

int n, m;
string s;
vi v;

void solve() {
	cin >> s;
	n = s.size();
	
	int l=0, r=n-1;
	bool pos = 0;
	
	repx(i, 1, n){
	    if (s[i] == s[i - 1]){
	        l = i;
	        break;
	    } 
	}
	
	repb(i, n){
	    if (i == 0) break;
	    if (s[i] == s[i - 1]){
	        r = i - 1;
	        break;
	    } 
	}
	
	cerr << s << " > " << l << " " << r << " " << n << el; 
	pos = (l >= r || l == 0); // Esta listo o hay uno fuera de lugar
	
	if (pos == 0){ // Puedo reordenar ocn una op
    	repx(i, l + 1, r + 1){
    	    if (s[i] == s[i - 1]){
    	        cerr << "NO" << el;
    	        cout << "NO" << el;
    	        return;
    	    } 
    	}
	}
	
	cerr << pos << el;
	cout << "YES" << el;
}

int main() {
	FastIO;
	int t = 1; cin >> t;
	while (t--) solve();
	return 0;
}