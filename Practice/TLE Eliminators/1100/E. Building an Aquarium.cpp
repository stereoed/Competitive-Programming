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
    int n, x; cin >> n >> x;
    vector<long long> v(n);
    for (auto& r : v) cin >> r;

    long long l = 0, r = 1e10;
    while (l < r){
        long long mid = l + (r - l + 1) / 2;

        long long copy_x = x;
        for (auto r : v) copy_x -= max<long long>(0, mid - r);
        if (copy_x >= 0) l = mid;
        else r = mid - 1;
    }

    cout << l << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}