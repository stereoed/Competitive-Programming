#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

long long D[10]{};

void solve(){
    string S; cin >> S;
    long long ans = 1;
    for (auto c : S) ans *= D[c - '0'];
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    D[0] = 1;
    for (int i = 1; i < 10; i++){
        D[i] = (i + 1) + D[i - 1];
    }

    int t = 1; cin >> t;
    while (t--) solve();
}