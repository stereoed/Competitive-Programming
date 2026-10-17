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
    string ANS = "", CUR(K, ' ');
    for (int n = 1; n <= N; n++){
        for (int i = 0; i < K; i++) CUR[i] = S[i % n];
        if (ANS.empty() || CUR < ANS) ANS = CUR;
    }
    cout << ANS << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
}