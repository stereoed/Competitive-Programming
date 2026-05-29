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

ll p, q;

// Con hint (1:37:00)* de clarificacion de enunciado

/*

    Se llena el grid entero:
    m*(n + 1) aristas horizontles
    n*(m + 1) aristas verticales
    
    Las simples (p) aportan solo en un sentido y deben ser mayor o igl a abs(m -n)
    Ademas H + V === p + 2q para que se llene. Despejamos una variable y probamos el resto

*/

void solve() {
	cin >> p >> q;
	ll E = p + 2LL * q;

	for (ll n = 1; n * n <= E; n++) {
		ll num = E - n;
		ll den = 2LL * n + 1;

		if (num <= 0) continue;
		if (num % den) continue;

		ll m = num / den;
		if (m <= 0) continue;

		if (abs(m - n) <= p) {
			cout << n << " " << m << el;
			return;
		}
	}
	cout << -1 << el;
}

int main() {
	FastIO;
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}