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

void solve() {
    vector<string> s(2);
    cin >> n >> s[0] >> s[1];
    vi cost(n + 1);

    cost[0] = 0;
    cost[1] = (s[0][0] != s[1][0]);

    int i = 2;
    while (i <= n) {
        int a = cost[i - 1] + (s[0][i - 1] != s[1][i - 1]); // col
        // 2 filas
        int b = cost[i - 2] + (s[0][i - 2] != s[0][i - 1]) + (s[1][i - 2] != s[1][i - 1]);
        cost[i] = min(a, b);
        i++;
    }

    cout << cost[n] << el;
}

int main() {
    FastIO;
    int t = 1; cin >> t;
    while (t--) solve();
    return 0;
}