#pragma GCC optimize("Ofast")

#if __has_include("stdc++.h")
#include "stdc++.h"
#else
#include <bits/stdc++.h>
#endif

#ifdef LOCAL
    #if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__)
    #else
    #define dump(...)
    #endif
#else
    #define dump(...)
#endif

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

const int MOD = 998244353;
const int INF = 1e9;

ll n, m, p, q, cur;
bool flag;
vvi adj;
vb seen;
vi ans;

/*
	PROBLEMA ACTUAL (NO EN CONTEST).
	
	Se debe poder resolver en O(1) por preg.
	
	Sabemos que:
	
	pref_i = i, 1, i+1, 0 al modear por 4.
	=> pref_r = pref_(l−1),
	Entonces para que el rango funcione podemos agrupar los que quedan en 
	0 y los que quedan en 1.
	
	

*/

void solve() {
	cin >> n >> m;
	
	ll l0, l1, r0, r1;
	
	// Cantidad de inicios (<= x)
	l0 = (m/4) + 1; // Al modear por 4 queda 1.
	l1 = (m+2)/4; //  Al modear por 4 queda 0. 
	
	// Cantidad de fines. Lo mismo pero restando los inicios.
	r0 = (n+1)/4 - l0 + 1;
	r1 = (n+3)/4 - l1;
	
	// ChatGPT wa ta fak
	ll ans1 = (__int128)l0 * r0 % MOD;
	ll ans2 = (__int128)l1 * r1 % MOD;
	cout << (ans1 + ans2) % MOD << el;
}

int main() {
	FastIO;
	int t = 1;
	cin >> t;
	
	while (t--) {
		solve();
	}
	return 0;
}