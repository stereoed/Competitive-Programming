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
    int n, m; cin >> n >> m;
    int o = 1;
    vector<bool> seen(n + 10, false);
    vector<int> pos(n + 1, -1), arr(n + 1, -1);
    seen[0] = true;
    rep(i, n){
        int val; cin >> val;
        pos[val] = i + 1;
        arr[i + 1] = val;
 
        if (!seen[val - 1]) {
            o++;
        }
        seen[val] = true;
    }
    //cout << el <<  "orig: " << o << el;
 
    int a, b;
    rep(i, m){
        cin >> a >> b;
        int x = arr[a], y = arr[b];
 
        auto bad = [&](int v)->int{
            if (v < 2 || v > n) return 0;
            return (pos[v] < pos[v - 1]) ? 1 : 0;
        };
 
        int cand[4] = {x, x + 1, y, y + 1};
        sort(cand, cand + 4);
        int k = int(unique(cand, cand + 4) - cand);
 
        rep(j, k) o -= bad(cand[j]);
 
        swap(arr[a], arr[b]);
        swap(pos[x], pos[y]);
 
        rep(j, k) o += bad(cand[j]);
 
        cout << o << el;
    }
 
}
 
int main() {
    FastIO;
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}