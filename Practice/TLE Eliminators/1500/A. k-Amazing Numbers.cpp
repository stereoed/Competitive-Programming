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
    int N; cin >> N;
    vector<pair<int, int>> V(N + 1);
    vector<int> bucket(N + 1);

    for (int i = 1; i <= N; i++) {
        int a; cin >> a;
        V[a] = {max(V[a].first, i - V[a].second), i};
    }

    for (int i = 0; i <= N; i++) bucket[i] = 1e9;
    for (int i = 1; i <= N; i++) {
        if (V[i].first == 0) continue;

        V[i] = {max(V[i].first, N + 1 - V[i].second), N};
        bucket[V[i].first] = min(bucket[V[i].first], i);
    }

    int ans = -1;
    for (int k = 1; k <= N; k++){
        if (bucket[k] != 1e9 && (ans == -1 || ans > bucket[k])) ans = bucket[k];
        cout << ans << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}