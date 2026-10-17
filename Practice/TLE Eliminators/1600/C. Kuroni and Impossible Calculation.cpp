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
    int N, M; cin >> N >> M;
    vector<int> V(N), cnt(M);
    for (auto& x : V) cin >> x;
    for (auto x : V){
        if (cnt[x % M]++){
            cout << "0\n";
            return;
        }
    }

    sort(V.rbegin(), V.rend());

    long long ans = 1;
    for (int i = 0; i < N; i++){
        for (int j = i + 1; j < N; j++){
            ans = (ans * (V[i] - V[j])) % M;
        }
    }
    cout << ans << '\n';
}

int main() {
    FastIO;

    int t = 1; //cin >> t;
    while (t--) solve();
}