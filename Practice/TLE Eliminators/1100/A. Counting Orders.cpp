#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

const int MOD = 1e9 + 7;

void solve(){
    int n; cin >> n;
    vector<int> A(n), B(n);
    for (auto& x : A) cin >> x;
    for (auto& x : B) cin >> x;
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());

    long long ans = 1; int pa = 0;
    for (int pb = 0; pb < n; pb++){
        while (pa < n && A[pa] > B[pb]) pa++;
        int len = pa - pb; dump(pa, pb, len);

        if (len <= 0){
            ans = 0;
            break;
        }

        ans = (ans * len) % MOD;
    }
    
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}