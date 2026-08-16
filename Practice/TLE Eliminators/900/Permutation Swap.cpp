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

long long n;

void solve() {
    cin >> n;
    vector<int> v(n);
    for (auto& x : v) cin >> x;

    int ans = -1;
    for (int i = 0; i < n; i++){
        const int id = i + 1;
        const int dif = abs(v[i] - id);

        if (ans == -1){
            ans = dif;
        }

        ans = gcd(ans, dif);
    }

    cout << ans << '\n';    
}

int main() {
    FastIO;

    int t = 1; cin >> t;
    while (t--) solve();
}