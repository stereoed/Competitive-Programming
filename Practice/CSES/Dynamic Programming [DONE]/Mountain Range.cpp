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
#define repb(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define ms(arr, val) memset(arr, val, sizeof(arr))
 
const int MOD = 1e9 + 7;
const ll INF = 1e18;
 
struct ST {
    int n;
    vi t;
 
    ST(int _n) {
        n = 1;
        while (n < _n) n <<= 1;
        t.assign(2 * n, 0);
    }
 
    void update(int p, int v) {
        p += n;
        t[p] = v;
        for (p >>= 1; p; p >>= 1) t[p] = max(t[p << 1], t[p << 1 | 1]);
    }
 
    int query(int l, int r) {
        if (l > r) return 0;
        l += n; r += n;
        int ans = 0;
        while (l <= r) {
            if (l & 1) ans = max(ans, t[l++]);
            if (!(r & 1)) ans = max(ans, t[r--]);
            l >>= 1; r >>= 1;
        }
        return ans;
    }
};
 
int main() {
    FastIO;
 
    int n; cin >> n;
    vi h(n);
    rep(i, n) cin >> h[i];
 
    vi L(n), R(n), dp(n);
    stack<int> s;
 
    rep(i, n) {
        while (!s.empty() && h[s.top()] < h[i]) s.pop();
        L[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }
 
    while (!s.empty()) s.pop();
 
    repb(i, n) {
        while (!s.empty() && h[s.top()] < h[i]) s.pop();
        R[i] = s.empty() ? n : s.top();
        s.push(i);
    }
 
    vi ord(n);
    iota(all(ord), 0);
 
    sort(all(ord), [&](int a, int b) {
        if (h[a] != h[b]) return h[a] < h[b];
        return a < b;
    });
 
    ST st(n);
    
    int p = 0;
    while (p < n) {
        int q = p;
        
        // Rango [) de misma altura 
        while (q < n && h[ord[q]] == h[ord[p]]) q++;
 
        repx(k, p, q){
            int i = ord[k];
            dp[i] = 1 + st.query(L[i] + 1, R[i] - 1);
        }
 
        repx(k, p, q){
            int i = ord[k];
            st.update(i, dp[i]);
        }
 
        p = q;
    }
 
    cout << st.query(0, n) << el;
    return 0;
}