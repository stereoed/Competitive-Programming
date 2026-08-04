#pragma GCC optimize("Ofast")
using namespace std;

#if __has_include("stdc++.h")
    #include "stdc++.h"
#else
    #include <bits/stdc++.h>
#endif

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(v) v.begin(), v.end()
#define el '\n'

int n, k;
void solve() {
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i > 0) a[i] += a[i - 1]; 
    }

    for (auto& x : b) cin >> x;

    long long ans = 0;
    int max_b = 0;
    for (int i = 0; i < min(n, k); i++){
        long long temp_ans = a[i];

        max_b = max(max_b, b[i]);
        temp_ans += max_b * (k - i - 1);

        ans = max(ans, temp_ans);
    }

    cout << ans << el;
}

int main() {
    FastIO;
    int t; cin >> t;
    while (t--)
    solve();
}