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
    int N, M; cin >> N >> M;
    long long a1; cin >> a1;

    long long g = 0;
    for (int i = 1; i < N; i++){
        long long ax; cin >> ax;
        g = gcd(g, ax - a1);
    }

    for (int i = 0; i < M; i++){
        long long bi; cin >> bi;
        cout << gcd(a1 + bi, g) << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
}