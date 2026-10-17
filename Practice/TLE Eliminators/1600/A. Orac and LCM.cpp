#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

vector<bool> is_prime(1e3, true);
vector<int> primes;

void solve(){
    int n; cin >> n;
    vector<long long> v(n), pref(n), suf(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];

        if (i > 0) pref[i] = gcd(v[i], pref[i - 1]);
        else pref[i] = v[i];
    }

    suf[n - 1] = v[n - 1];
    for (int i = n - 2; i >= 0; i--){
        suf[i] = gcd(v[i], suf[i + 1]);
    }

    long long ans = lcm(suf[1], pref[n - 2]);
    for (int i = 1; i < n - 1; i++) {
        ans = lcm(ans, gcd(pref[i - 1], suf[i + 1]));
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    for (int i = 2; i < 1e3; i++){
        if (!is_prime[i]) continue;
        primes.push_back(i);
        for (int x = i * i; x < 1e3; x += i) is_prime[x] = false;
    }

    int t = 1; //cin >> t;
    while (t--) solve();
}