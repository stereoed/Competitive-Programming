#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

int n;
void solve(){
    cin >> n;

    vector<long long> A(n), B(n);
    for (auto& x : A) cin >> x;
    for (auto& x : B) cin >> x;

    long long max_A = 0, max_B = 0;
    for (int i = n - 1; i >= 0; i--){
        long long cmA = max_A, cmB = max_B;
        max_A = max(max_A, A[i] + cmB);
        max_B = max(max_B, B[i] + cmA);
    }

    cout << max(max_A, max_B) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
}