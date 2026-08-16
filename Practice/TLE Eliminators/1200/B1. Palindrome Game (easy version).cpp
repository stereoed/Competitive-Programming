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

long long n;
string s;
 
void solve() {
    cin >> n >> s;
    int zero = 0;
    for (const char c : s) zero += c == '0';
 
    dump(s[(n) / 2], n%2==0 || s[(n + 1) / 2] == '1')
    if (zero == 1 || n%2==0 || s[n / 2] == '1') {
        cout << "BOB\n";
        return;
    }
 
    if (zero % 2 == 0){
        cout << "DRAW\n";
        return;
    }

    cout << "ALICE\n";
}

int main() {
    FastIO;
    int t = 1; cin >> t;
    while (t--) solve();
}