#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__)
#else
    #define dump(...)
#endif

long long n, q, a, b;

void solve(){
    cin >> n >> q;
    map<int, int> m;
    long long sum = 0, def = -1;

    for (int i = 1; i <= n; i++){
        int x; cin >> x;
        m[i] = x;
        sum += x;
    }

    for (int i = 1; i <= q; i++){
        int x; cin >> x; 
        
        if (x == 1){
            cin >> a >> b; dump(sum, x, a, b);
            if (m.count(a)) sum -= m[a];
            else sum -= def;

            m[a] = b;
            sum += b;
        } else {
            cin >> b;

            def = b;
            m.clear();
            sum = n * b;
        }

        cout << sum << '\n';        
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; // cin >> t;

    while (t--) {
        solve();
    }
}