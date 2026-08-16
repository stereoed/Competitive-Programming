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
    vector<int> v(n);

    int only = -1;
    for(auto& x : v) {
        cin >> x;
        if (only == -1) only = x;
        if (only != x) only = -2;
    }

    if (only > 0){
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    int last = -1;
    vector<int> repeats;
    for (int i = 0; i < n; i++){
        if (v[i] == v[0]) {
            repeats.push_back(i + 1); 
            continue;
        }

        last = i + 1;
        cout << 1 << " " << i + 1 << '\n';
    }

    for (int i = 1; i < (int)repeats.size(); i++){
        cout << last << " " << repeats[i] << '\n';
    }
}

int main() {
    FastIO;
    int t = 1; cin >> t;
    while (t--) solve();
}