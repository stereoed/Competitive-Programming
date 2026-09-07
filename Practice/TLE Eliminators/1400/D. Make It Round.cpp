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
    long long n, m; cin >> n >> m;
    
    long long ans = n, used = 1;
    for (long long zeroes = 10; zeroes < 1e18; zeroes *= 10){
        long long g = gcd(n % zeroes, zeroes);
        if (m < zeroes / g) break;
        
        used = zeroes / g;
        ans = n * used;
    }

    used = max(used, 1LL);
    m = m - used;
    ans += (m / used) * ans;
    
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}