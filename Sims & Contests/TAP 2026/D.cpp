#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

const int MAXN = 1e6;

void solve(){
    string S; cin >> S;
    int N = S.back() - '0';
    vector<int> V(MAXN);

    long long carry = N;
    V[MAXN - 1] = 0;
    int next = S.size() - 2;

    for (int i = MAXN - 2; i >= 0; i--){
        if (next >= 0) carry += 9 * (S[next--] - '0');

        V[i] = carry % 10;
        carry /= 10;
    }

    long long s = 0;
    for (auto x : V) s += x;

    while (N < s){
        N += 10;
        carry = 1;

        for (int i = MAXN - 2; i >= 0; i--){
            carry += V[i];

            s += (carry % 10 - V[i]);
            V[i] = carry % 10;
            carry /= 10;

            if (carry == 0) break;
        }
    }

    cout << N << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
}