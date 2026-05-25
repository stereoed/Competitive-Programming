#include <bits/stdc++.h>
using namespace std;
 
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, x;
    cin >> n >> x;
    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];
 
    const int INF = 1e9;
    vector<int> dist(x + 1, 0);
    dist[0] = 1;
 
    rep(s, x){
        for (int coin : c) {
            int ns = s + coin;
            if (ns > x) continue;
            dist[ns] += dist[s];
            dist[ns] %= MOD;
        }
    }
 
    cout << (dist[x] == INF ? -1 : dist[x]) << "\n";
}