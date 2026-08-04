#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__)
#else
    #define dump(...)
#endif


int a, b, c, d;

void solve(){
    cin >> a >> b >> c >> d;
    
    if (b > d){
        cout << "-1\n";
        return;
    }

    int ans = d - b; // {a + d - b, d}
    a += d - b;

    dump(ans, a, d, b, d);

    if (a < c){
        cout << "-1\n";
        return;
    }

    ans += a - c;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;

    while (t--) {
        solve();
    }
}
