#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void solve() {
    int n, k; cin >> n >> k;
    set<pair<int, int>> data;

    for (int i = 1; i <= n; i++){
        int a; cin >> a;
        data.insert({(k - (a%k))%k, i});
    }

    for (int i = 0; i < n; i++){
        const auto& [h, id] = *data.begin(); dump(h, id);
        cout << id << ' ';
        data.erase(*data.begin());
    }
    cout << '\n';

}

int main() {
    FastIO;
    int t = 1; cin >> t;
    while (t--) solve();
}