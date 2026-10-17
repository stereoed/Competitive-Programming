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
    string S; cin >> S;
    
    int best = 1, most_kept = 0;
    vector<pair<int, char>> cnts(27);
    for (auto c : S) cnts[c - 'a'].first++;
    for (int i = 0; i < 26; i++) cnts[i].second = i + 'a';
    sort(cnts.rbegin(), cnts.rend());

    for (int x = 1; x <= 26; x++){
        if (N % x) continue;

        int kept = 0;
        int obj = N / x;

        for (int i = 0; i < x; i++) kept += min(obj, cnts[i].first);

        if (kept > most_kept){
            most_kept = kept;
            best = x;
        }
    }

    cout << N - most_kept << '\n';

    int obj = N / best;

    vector<int> target(26);
    for (int i = 0; i < best; i++){
        auto [cnt, c] = cnts[i];
        target[c - 'a'] = obj;
    }

    vector<int> free;
    for (int i = 0; i < N; i++) if (target[S[i] - 'a']-- <= 0) free.push_back(i);

    for (int i = 0; i < best; i++){
        auto [cnt, c] = cnts[i];
        while (target[c - 'a']-- > 0){
            S[free.back()] = c;
            free.pop_back();
        }
    }

    cout << S << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}