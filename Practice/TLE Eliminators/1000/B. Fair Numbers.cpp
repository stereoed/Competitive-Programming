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
    long long n; cin >> n;
    while (true){
        string s = to_string(n);
        bool flag = true;

        for (char c : s){
            if (c == '0') continue;
            if (n % (c - '0') > 0){
                n++;
                flag = false;
                break;
            }
        }

        if (flag) break;
    }
    cout << n << '\n';
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}