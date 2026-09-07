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
    int n; cin >> n;
    vector<pair<int, int>> v(n);
    for (auto& [ff, ss] : v) cin >> ff >> ss;
    
    int l = 0, r = 1e9;
    while (l < r){
        int mid = l + (r - l) / 2;
        pair<int, int> pos = {0, 0};
        bool ok = true;

        for (const auto [ff, ss] : v) {
            pos = {pos.first - mid, pos.second + mid};

            if (pos.second < ff || pos.first > ss) ok = false;
            pos = {max(pos.first, ff), min(pos.second, ss)};
        }


        if (ok) r = mid;
        else l = mid + 1;
    }

    cout << l << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}