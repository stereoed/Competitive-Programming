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
    int N, K; cin >> N >> K;
    string S; cin >> S;

    vector<vector<int>> cnt(K, vector<int>(26));
    for (int i = 0; i < K; i++){
        for (int j = i; j < N; j += K){
            cnt[i][S[j] - 'a']++;
        }
    }


    for (int i = 0; i < K / 2; i++){
        for (int j = 0; j < 26; j++) cnt[i][j] += cnt[K - i - 1][j];
    }

    long long ans = 0;
    for (int i = 0; i < (K + 1) / 2; i++){
        int max_count = 0;
        for (int j = 0; j < 26; j++) max_count = max(max_count, cnt[i][j]);
        int mult = i < K / 2 ? 2 : 1;
        ans += mult * N / K - max_count;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}