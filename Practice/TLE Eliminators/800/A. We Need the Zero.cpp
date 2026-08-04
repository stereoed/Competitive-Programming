#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__)
#else
    #define dump(...)
#endif


int n;

void solve(){
    cin >> n;
    int X = 0;
    
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        X ^= a;
    }

    if (n&1 || X == 0){
        cout << X << '\n';
        return;
    }

    cout << -1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;

    while (t--) {
        solve();
    }
}
