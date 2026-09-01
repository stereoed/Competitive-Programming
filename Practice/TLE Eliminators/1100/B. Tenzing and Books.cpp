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

    int cur = 0;
    for (int i = 0; i < 3; i++){
        bool in = true;

        for (int j = 0; j < n; j++){
            int aux; cin >> aux;
            if (!in || aux & ~x){
                in = false;
                continue;
            }
            cur |= aux;
        }
    }

    cout << (cur == x ? "Yes" : "No") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}