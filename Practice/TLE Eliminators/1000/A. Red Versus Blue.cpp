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
    int n, r, b; cin >> n >> r >> b;
    string s = "";

    const int cb = b;
    for (int i = 0; i <= cb; i++){
        int row = (r + b) / (b + 1);

        s.append(row, 'R');
        if (b) s += 'B';

        b--;
        r -= row;
    }

    cout << s << '\n';    
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}