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
 
int main() {
    FastIO;
 
    int n; cin >> n;
    vector<string> grid(n);
    rep(i, n) cin >> grid[i];
 
    string ans;
    ans.pb(grid[0][0]);
 
    vii cur, nxt;
    cur.pb({0, 0});
 
    vector<vi> seen(n, vi(n, 0));
    int mark = 1;
    seen[0][0] = mark;
 
    rep(step, 2 * n - 2) {
        char best = 'z' + 1;
        nxt.clear();
        mark++;
 
        for (auto [i, j] : cur) {
            if (i + 1 < n) best = min(best, grid[i + 1][j]);
            if (j + 1 < n) best = min(best, grid[i][j + 1]);
        }
 
        for (auto [i, j] : cur) {
            if (i + 1 < n && grid[i + 1][j] == best && seen[i + 1][j] != mark) {
                seen[i + 1][j] = mark;
                nxt.pb({i + 1, j});
            }
            if (j + 1 < n && grid[i][j + 1] == best && seen[i][j + 1] != mark) {
                seen[i][j + 1] = mark;
                nxt.pb({i, j + 1});
            }
        }
 
        ans.pb(best);
        cur = nxt;
    }
 
    cout << ans << el;
}