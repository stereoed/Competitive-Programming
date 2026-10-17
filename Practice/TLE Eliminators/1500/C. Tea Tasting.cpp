#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

typedef long long ll;
typedef pair<int, int> pii;

const int M = 1000000007;

void solve(){
    int n; cin >> n;
    vector<long long> A(n + 1), B(n + 1);
    for (int i = 1; i <= n; i++) cin >> A[i];
    for (int i = 1; i <= n; i++) {
        cin >> B[i];
        B[i] += B[i - 1];   
    }

    vector<long long> ans(n + 1), cnt(n + 1);
    for (int i = 1; i <= n; i++){
        long long stop = A[i] + B[i - 1];
        auto it = upper_bound(B.begin(), B.end(), stop);

        cnt[i]++;
        int idx = it - B.begin();
        if (idx <= n) {
            cnt[idx]--;
            ans[idx] += stop - B[idx - 1];
        }
    }

    dump(ans, cnt);

    for (int i = 1; i <= n; i++) {
        cnt[i] += cnt[i - 1];
        cout << 1LL * cnt[i] * (B[i] - B[i - 1]) + ans[i] << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}