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
vii da = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
vii dd = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int n, k;

void solve() {
    cin >> n >> k;
    vector<bool> arr(n); rep(i, n) { 
        int p = 0;
        cin >> p;
        arr[i] = p == 1;
    }
    cin >> k; k--;
    int a = arr[0] == 1, b = arr[n-1] == 1, c = arr[0] == 0, d = arr[n-1] == 0;
    
    // Todos 0
    repx(i, 1, k + 1) if (arr[i] != arr[i - 1]) a++;
    repx(i, k + 1, n) if (arr[i] != arr[i - 1]) b++;
    int ans1 = max(a, b) + (arr[k] == 0 && max(a, b)&1) + (arr[k] == 1 && !(max(a, b)&1));
    
    // Todos 1
    repx(i, 1, k + 1) if (arr[i] != arr[i - 1]) c++;
    repx(i, k + 1, n) if (arr[i] != arr[i - 1]) d++;
    int ans2 = max(c, d) + (arr[k] == 1 && max(c, d)&1) + (arr[k] == 0 && !(max(c, d)&1));
    
    if (arr[k] == 1) cout << ans2 << el;
    else cout << ans1 << el;
}

int main() {
    FastIO;
    int t = 1; cin >> t;
    while (t--) solve();
    return 0;
}