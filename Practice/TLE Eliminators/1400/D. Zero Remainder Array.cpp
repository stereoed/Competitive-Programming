#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

void solve(){
    int n, k; cin >> n >> k;
    map<int, int> cnt;

    long long ans = 0;
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        int left = (a % k);
        if (left == 0) continue;
        ans = max(ans, 1 + 1LL * cnt[k - left]++ * k + 1LL * (k - left));
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}