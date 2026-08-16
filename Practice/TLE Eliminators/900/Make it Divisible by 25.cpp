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
#define all(v) v.begin(), v.end()

string s;

int min_removals_to_k(const string& x, const string k){
    int ptr = k.size() - 1, out = 0;
    for (int i = x.size() - 1; i >= 0; i--){
        if (x[i] == k[ptr]) ptr--;
        else out++;
        
        if (ptr < 0) break;
    }
    return out;
}

void solve() {
    cin >> s;
    int ans = 18;
    ans = min(ans, min_removals_to_k(s, "25"));
    ans = min(ans, min_removals_to_k(s, "50"));
    ans = min(ans, min_removals_to_k(s, "75"));
    ans = min(ans, min_removals_to_k(s, "00"));
    cout << ans << '\n';
}

int main() {
    FastIO;
    int t = 1; cin >> t;
    while (t--) solve();
}