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

int n;
string a, b;

void solve() {
    cin >> n >> a >> b;
    vector<int> pre(n);
    for (int i = 0; i < n; i++){
        pre[i] = (a[i] == '1' ? 1 : -1);
        if (i > 0) pre[i] += pre[i-1];
    }

    dump(pre);
    bool flip = false;
    for (int i = n - 1; i >= 0; i--){
        if ((a[i] == b[i]) ^ flip) continue;

        if (pre[i] != 0){
            cout << "NO\n";
            return;
        }

        flip = !flip;
    }


    cout << "YES\n";    
}

int main() {
    FastIO;
    int t = 1; cin >> t;
    while (t--) solve();
}