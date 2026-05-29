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

int n, k;

// Originalmente pensamos q era una dp de cual nos convenia mover, pero termino siendo ungreedy.
// Lo unico q no me queda claro es como nace la ultima comparacion del max, para q me ayutes nano

void solve() {
    cin >> n >> k;
    vi a(n); rep(i, n) cin >> a[i];
    vi l(k + 2); rep(i, k) cin >> l[i + 1];
    l[0] = 1; l[k + 1] = n;
    
    for (auto& aux : l) aux--;
    int sm = 0, mx = 0;
    
    rep(i, k + 1){
        int aux = 0;
        repx(x, l[i], l[i + 1]) aux += a[x] != a[x+1];
        aux += aux&1;
        mx = max(mx, aux);
        sm += aux;
    }
    
    cout << max(sm/2, mx) << el;
}
    
int main() {
    FastIO;
    int t = 1; cin >> t;
    while (t--) solve();
    return 0;
}
