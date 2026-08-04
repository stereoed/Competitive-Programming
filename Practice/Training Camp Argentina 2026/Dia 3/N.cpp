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

void solve() {
    cin >> n;
    vector<int> a(n);

    for (auto& x : a){
        cin >> x;
    }

    vector<int> ac = a;
    sort(all(ac));

    int two = 2;

    for (int i = 0; i < n; i++){
        if (a[i] != ac[i]) two--;
    }

    cout << (two >= 0 ? "YES" : "NO") << el;
}

int main() {
    FastIO;
    int t = 1; // cin >> t;
    while (t--)
    solve();
}