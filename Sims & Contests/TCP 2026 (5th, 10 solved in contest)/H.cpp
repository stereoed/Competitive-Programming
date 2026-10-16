#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

string S = "regalo";
const int MOD = 'z' - 'a' + 1;

void solve(){
    int N; cin >> N;
    vector<int> C(N);
    for (auto& x : C) cin >> x;

    sort(S.begin(), S.end());

    int ans = -1;
    for (int i = 0; i < N; i++){
        string X; cin >> X;

        if (ans == -1){
            for (auto& c : X){
                c = tolower(c);
                c = (((c - 'a' - C[i] + MOD) % MOD) + MOD) % MOD + 'a';
            }
            dump(X);
            sort(X.begin(), X.end());
            if (S == X) ans = i;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
}