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
    long long n, c; cin >> n >> c;
    vector<int> s(n);
    for (auto& x : s) cin >> x;

    long long l = 1, r = 5 * 1e8;
    while (l < r){
        long long mid = l + (r - l + 1) / 2;

        long long used = 0;
        for (auto x : s) {
            used += (2 * mid + x) * (2 * mid + x);
            if (used > c || used < 0) {
                used = c + 1;
                break;
            } 
        }

        if (used > c) r = mid - 1;
        else l = mid;
    }

    cout << l << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}