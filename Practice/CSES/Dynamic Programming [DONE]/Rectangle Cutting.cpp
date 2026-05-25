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
 
int dp(int a, int b, vvi& v){
    if (v[a][b] != 1e9) return v[a][b];
 
    repx(i, 1, a){
        v[a][b] = min(v[a][b], dp(i, b, v) + dp(a - i, b, v));
    }
    repx(j, 1, b){
        v[a][b] = min(v[a][b], dp(a, j, v) + dp(a, b - j, v));
    }
    
    ++v[a][b];
    v[b][a] = v[a][b];
    return v[a][b];
}
 
int main() {
    FastIO;
 
    int a, b; cin >> a >> b;
    if (a < b) swap(a, b);
    
    vvi v(501, vi(501, 1e9));
    rep(i, 501) v[i][i] = 0;
    
    cout << dp(a, b, v) << el;
}