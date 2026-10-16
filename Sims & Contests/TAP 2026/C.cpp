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
    vector<int> A(N + 1), B(N + 1);
    for (int i = 1; i <= N; i++) cin >> A[i];
    for (int i = 1; i <= N; i++) cin >> B[i];
    dump(A);
    dump(B);

    vector<vector<int>> DP(2, vector<int>(N + 1)); // Next turn, index;
    DP[0][N] = A[N]; 
    DP[1][N] = B[N];

    for (int i = N - 1; i >= 0; i--){
        DP[0][i] = max(DP[0][i + 1], min(A[i], DP[1][i + 1]));
        DP[1][i] = min(DP[1][i + 1], max(B[i], DP[0][i + 1]));
    }
    dump(DP);

    cout << DP[0][0] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
}