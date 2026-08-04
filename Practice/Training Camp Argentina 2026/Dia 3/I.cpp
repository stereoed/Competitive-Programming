#pragma GCC optimize("Ofast")
using namespace std;

#if __has_include("stdc++.h")
    #include "stdc++.h"
#else
    #include <bits/stdc++.h>
#endif

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(v) v.begin(), v.end()
#define el '\n'

int l, r;
void solve() { // t -> 1e5 -> log N / 1
    cin >> l >> r;
    int x{-1}, y{-1};
    
    if (2 * l <= r){
        x = l;
        y = 2 * l;
    }

    cout << x << " " << y << el;
}

int main() {
    FastIO;
    int t; cin >> t;
    while (t--)
    solve();
}