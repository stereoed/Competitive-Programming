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

int n, a, b, c;
vector<pair<int, int>> delta = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void solve() {
    cin >> n >> a >> b >> c;
    if (b > c) swap(b, c);
    if (a > b) {
        swap(a, b);
        if (b > c) swap(b, c);
    }
    dump(n, a, b, c);

    const int max_a = n / a;
    int ans = 0;

    dump(max_a);
    for (int na = 0; na <= max_a; na++){
        const int max_b = (n - na * a) / b;
        dump(max_b)

        for (int nb = 0; nb <= max_b; nb++){
            const int rem = n - na * a - nb * b;
            dump(na, na * a, nb, nb * b, rem, c)
            if (rem % c == 0){
                dump(na + nb + rem / c)
                ans = max(ans, na + nb + rem / c);
            }
        }
    }

    cout << ans << el;
}

int main() {
    FastIO;
    int t = 1; //cin >> t;
    while (t--) solve();
}