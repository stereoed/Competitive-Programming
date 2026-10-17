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
    ll ans = 0, sum = 0;

    vector<long long> v(n);
    for (auto& x : v) {
        cin >> x;
        sum += x;
    }
    sort(v.rbegin(), v.rend());

    ans = (sum + 1) / 2;
    
    long long rem = sum / 2;
    for (int i = 0; i < n; i++){
        if (rem <= 0) break;
        rem -= v[i];
        ans++;
    }

    
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}