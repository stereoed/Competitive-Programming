#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

void solve() {
    long long a, b; cin >> a >> b;

    long long ans = 0;
    if (a > b) swap(a, b);

    for (auto x : vector<int>{8, 4, 2}){
        while (a * x <= b){
            ans++;
            a *= x;
        }
    }

    cout << (a == b ? ans : -1) << '\n';
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}