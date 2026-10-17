#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v) cin >> x;

    int ans = 1e9, cnt1 = 0;
    for (auto x : v) cnt1 += (x == 1);
    if (cnt1) ans = n - cnt1;

    for (int l = 0; l < n; l++) {
        int g = v[l];
        for (int r = l + 1; r < n; r++) {
            g = gcd(v[r], g);
            if (g == 1) { ans = min(ans, r - l + n - 1); break; } // added break
        }
    }

    cout << (ans == 1e9 ? -1 : ans) << '\n';
    return 0;
}