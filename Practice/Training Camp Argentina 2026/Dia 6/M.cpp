#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

void solve() {
    int n, k; cin >> n >> k;
    
    int prev_inter = 0;
    int curr_inter = k / n;
    int new_k = k;

    while (prev_inter != curr_inter){
        new_k += curr_inter - prev_inter;
        prev_inter = curr_inter;
        curr_inter = new_k / n;
    }
    cout << new_k << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}