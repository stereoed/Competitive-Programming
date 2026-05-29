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
int n, m, d0, d1, d2;

vii da = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
vii dd = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

ll binpow(ll a, ll e){
	ll r = 1;
	while (e){
		if (e & 1) r = r * a % MOD;
		a = a * a % MOD;
		e >>= 1;
	}
	return r;
}

ll get_expected(bool n0, int n1, int n2, bool v0, bool v1, bool v2){
    ll p0 = (v0 ? 512 : (n0 ? 256 : 0)); // Probabilida q sea p0
    ll q0 = 512 - p0; // Probabilida q no sea p0

    ll p1 = (v1 ? 512 : 512 - (512 >> n1)); // Probabilida q sea p1
    ll q1 = 512 - p1; // Probabilida q sea no p1

    ll p2 = (v2 ? 512 : 512 - (512 >> n2)); // Probabilida q sea p2

    ll expected = 0;
    expected += 1LL * d0 * p0;
    expected += 1LL * d1 * q0 * p1 / 512;
    expected += 1LL * d2 * q0 * q1 * p2 / 512 / 512;

    return expected;
}

void solve() {
	cin >> n >> m >> d0 >> d1 >> d2;
	ll p = 0;
	vector<string> mat(n);

	rep(i, n) cin >> mat[i];

	rep(i, n){
		rep(j, m){
			char c = mat[i][j];
			bool v0{c == 'V'}, v1{0}, v2{0}, n0{c == '?'};
			int n1{0}, n2{0};
			
			for (auto& [x, y] : da){
				int ni = i + x, nj = j + y;
				if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
				n1 += mat[ni][nj] == '?';
				v1 |= mat[ni][nj] == 'V';
			}
			
			for (auto& [x, y] : dd){
				int ni = i + x, nj = j + y;
				if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
				n2 += mat[ni][nj] == '?';
				v2 |= mat[ni][nj] == 'V';
			}
			
			p += get_expected(n0, n1, n2, v0, v1, v2);
		}
	}
	
	cout << p % MOD * binpow(512, MOD - 2) % MOD << el;
}

int main() {
    FastIO;
    int t = 1;
    while (t--) solve();
    return 0;
}