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
    long long ans = 0;
    vector<pair<int, int>> W(N);
    for (int i = 0; i < N; i++) {
        cin >> W[i].first;
        ans += W[i].first;
    }

    for (int i = 0; i < N - 1; i++){
        int a, b; cin >> a >> b; a--; b--;
        W[a].second++;
        W[b].second++;
    }

    sort(W.rbegin(), W.rend());
    int ptr = 0;
    while (ptr < N - 1 && W[ptr].second <= 1) ptr++;
    for (int i = 0; i < N - 1; i++){
        dump(ptr);
        cout << ans << ' ';

        ans += W[ptr].first;

        W[ptr].second--;
        while (ptr < N - 1 && W[ptr].second <= 1) ptr++;
    }
    cout << '\n';    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}