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
    int N; cin >> N;
    vector<pair<int, int>> E(N);
    for (auto& [ff, ss] : E) cin >> ff >> ss;
    sort(E.begin(), E.end());
    
    int r1 = -1, r2 = -1;
    for (const auto& [ff, ss] : E){
        if (ff <= r1){
            cout << "NO\n";
            return;
        }
        
        r1 = ss;
        if (r1 > r2) swap(r1, r2);
    }
    
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
}