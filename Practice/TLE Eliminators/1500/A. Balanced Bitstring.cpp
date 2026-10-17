#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

void YN(bool ok){
    cout << (ok ? "YES\n" : "NO\n");
}


void solve(){
    int N, K; cin >> N >> K;
    string S; cin >> S;

    int one = 0, zero = 0;
    for (int i = 0; i < K; i++){
        char c = '?';
        for (int j = i; j < N; j += K){
            if (c == '?') c = S[j];
            else if (S[j] != '?' && c != S[j]) {
                YN(0);
                return;
            }
        }
        for (int j = i; j < N; j += K) S[j] = c;

        one += (c == '1');
        zero += (c == '0');
    }
    YN(abs(one - zero) <= K - one - zero);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}