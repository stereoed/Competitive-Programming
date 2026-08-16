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

long long n, q;

void solve() {
    cin >> n;

    int ans = 0, cnt = 0;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        if (x > 0) {
            cnt++;
            continue;
        }
        else if (cnt == 0) continue;

        ans++;
        cnt = 0;
    }

    if (cnt > 0) ans++;
    cout << min(ans, 2) << '\n';
}

int main() {
    FastIO;

    int t = 1; cin >> t;
    while (t--) solve();
}