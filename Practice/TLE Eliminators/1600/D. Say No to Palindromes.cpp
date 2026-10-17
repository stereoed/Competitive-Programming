#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
#include "cpp-dump.hpp"
#define dump(...) cpp_dump(__VA_ARGS__);
#else
#define dump(...)
#endif

const int MAXN = 2e5 + 5;
string period[] = {"abc", "acb", "bac", "cab", "bca", "cba"};

int error[6][MAXN]{};

void solve(){
    int N, M; cin >> N >> M;
    string S; cin >> S;

    for (int i = 0; i < 6; i++){
        auto& P = period[i];
        for (int j = 0; j < N; j++){
            error[i][j + 1] = error[i][j] + (S[j] != P[j%3]);
        }
    }

    dump(error);
    for (int i = 0; i < M; i++){
        int l, r; cin >> l >> r;

        int ans = r - l + 1;
        for (int i = 0; i < 6; i++) ans = min(ans, error[i][r] - error[i][l - 1]);

        cout << ans << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
}