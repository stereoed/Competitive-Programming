#pragma GCC optimize("Ofast")
using namespace std;
#include <bits/stdc++.h>

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

long long n, k;
void solve() {
    cin >> n >> k;
    double ans = 0, div = n - k + 1, sum = 0;
    vector<int> v(n);
    for (auto& x : v) cin >> x;

    int r = 0;
    for (int l = 0; l < div; l++){
        while (r < l + k) {
            sum += v[r++];
        }

        dump(sum, div);
        ans += sum / div;

        sum -= v[l];
    }

    cout << fixed << setprecision(7);
    cout << ans << '\n';
}

int main() {
    FastIO;
    int t = 1; //cin >> t;
    while (t--) solve();
}