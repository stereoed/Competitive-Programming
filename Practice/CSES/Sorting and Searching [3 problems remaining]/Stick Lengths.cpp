#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <set>
#include <cmath>
#include <string.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define el '\n'
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repx(i, a, n) for (int i = (int)a; i < (int)(n); i++)
#define repb(i, n) for (int i = n - 1; i >= 0; i--)
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define ms(arr, val) memset(arr, val, sizeof(arr))
 
void solve(){
    int n; cin >> n;
    vector<ll> vals(n);
    rep(i, n) cin >> vals[i];
    sort(all(vals));
 
 
    if (n == 1) {
        cout << 0 << el;
        return;
    }
 
    int median = n / 2;
 
    ll sum = 0;
    rep(i, n) sum += llabs(vals[i] - vals[median]);
    ll o = sum;
 
    sum = 0;
    rep(i, n) sum += llabs(vals[i] - vals[median + 1]);
    o = min(o, sum);
 
    cout << o << el;
}
 
 
int main() {
    FastIO;
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}