#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

const int MAXN = 1e3;
long long V[MAXN]{}; 
int N, K;

bool ok(int i, int score){
    long long req = 0;
    bool pos = false;

    while (i < N && !pos && req <= K){
        if (V[i] >= score) pos = true;
        else {
            req += score - V[i];
            score--;
            i++;
        }
    }

    return pos && (req <= K);
}

void solve(){
    cin >> N >> K;
    long long ans = 0;

    for (int i = 0; i < N; i++) {
        cin >> V[i];
        ans = max(ans, V[i]);
    }

    for (int i = 0; i < N; i++){
        long long l = V[i], r = ans + N;
        while (l < r){
            long long final_score = l + (r - l + 1) / 2;
            if (ok(i, final_score)) l = final_score;
            else r = final_score - 1;
        }

        ans = max(ans, l);
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}