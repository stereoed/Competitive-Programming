#pragma GCC optimize("Ofast")
using namespace std;

#if __has_include("stdc++.h")
    #include "stdc++.h"
#else
    #include <bits/stdc++.h>
#endif

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(v) v.begin(), v.end()
#define el '\n'

long long n;
void solve() {
    cin >> n;
    vector<int> v(n), val_to_id(2*n + 5);

    long long ans = 0;
    for (int i = 1; i<= n; i++){
        auto& ai = v[i-1];
        cin >> ai;

        for (int aj = 1; ai * aj - i <= n; aj++){
            if (ai * aj - i <= 0) continue;
            if (val_to_id[aj] == ai * aj - i) ans++;
        }

        val_to_id[ai] = i;
    }

    cout << ans << '\n';
}

int main() {
    FastIO;
    int t = 1; cin >> t;
    while (t--) solve();
}