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

void solve() {
    int N; cin >> N;
    vector<pair<int, int>> V(N);
    for (auto& [less, more] : V) cin >> more >> less;
    dump(V);

    int l = 1, r = N;
    while (l < r){
        int mid = l + (r - l + 1) / 2;
        dump(l, r, mid);

        int nm = mid - 1;
        int nl = 0;

        for (int i = 0; i < N; i++){
            auto& [less, more] = V[i];
            if (less >= nl && more >= nm){
                nl++;
                nm--;
            }
        }

        dump(nl, nm);
        if (nm < 0) l = mid;
        else r = mid - 1;
    }

    cout << l << '\n';
}

int main() {
    FastIO;

    int t = 1; cin >> t;
    while (t--) solve();
}