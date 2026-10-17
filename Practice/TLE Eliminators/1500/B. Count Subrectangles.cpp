#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

const int MAXN = 40005;

void solve(){
    int N, M; long long K;
    cin >> N >> M >> K;

    vector<long long> divisors;
    for (long long i = 1; i * i <= K; i++){
        if (K % i) continue;
        divisors.push_back(i);
        if (i * i < K) divisors.push_back(K / i);
    }

    // CNT[0] = row axis, CNT[1] = column axis
    vector<vector<long long>> CNT(2, vector<long long>(MAXN + 1, 0));
    int len[2] = {N, M};

    for (int t = 0; t < 2; t++){
        vector<long long> S(MAXN + 2, 0);
        int aux = 0;
        for (int j = 0; j <= len[t]; j++){
            int a = 0;
            if (j < len[t]) cin >> a;
            if (a == 1) aux++;
            else { if (aux) S[aux]++; aux = 0; }
        }
        for (int j = len[t]; j >= 1; j--) S[j] += S[j + 1];
        for (int j = len[t]; j >= 1; j--) CNT[t][j] = CNT[t][j + 1] + S[j];
    }

    long long ans = 0;
    for (long long p : divisors){
        long long q = K / p;
        if (p <= N && q <= M) ans += CNT[0][p] * CNT[1][q];
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
}