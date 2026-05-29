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

int n, m, a, b;

bool gq(int lado, int b){
    int paso = b % lado;
    return __gcd(paso, lado) == 1; 
}

void solve() {
    cin >> n >> m >> a >> b;
    bool flag = (gq(n, a) && gq(m, b)); // Se puede dar la vuelta
    
    if (flag){ // Pero intercalado?
        flag &= (__gcd(n, m) <= 2);
    }
    
    cout << ( flag ? "yes" : "no") << el;
}
    
int main() {
    FastIO;
    int t = 1; cin >> t;
    while (t--) solve();
    return 0;
}
