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
    string s; cin >> s; dump(s);
    int n = s.size();
    bool ok = true;

    set<char> uniques;
    for (char c : s) uniques.insert(c);

    string ts = "";
    int tn = uniques.size();
    for (int i = 0; i < tn; i++){
        const char c = s[i];

        if (uniques.count(c) == 0) ok = false;
        uniques.erase(c);
        ts += c;
    }

    for (int i = 0; i < n; i += tn){
        for (int j = 0; j < tn; j++){
            if (i + j >= n) break;
            ok &= ts[j] == s[i + j];
        }
    }

    cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}