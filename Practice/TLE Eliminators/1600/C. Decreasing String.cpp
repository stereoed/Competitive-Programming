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
    string S; cin >> S;
    long long POS; cin >> POS; POS--;
    long long N = S.size(), K = 0;
    
    while(POS >= N){
        POS -= N;
        N--;
        K++;
    }

    dump(POS, N, K);

    string S2 = "";
    for (char c : S){
        while (S2.size() && S2.back() > c && K > 0){
            S2.pop_back();
            K--;
        }
        S2 += c;
    }

    cout << S2[POS];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}