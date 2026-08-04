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
    vector<int> a(n);
    for (auto& x : a) cin >> x;

    // Ahora preservamos el orden...
    vector<int> distinct;
    {
        vector<bool> seen(n + 1, false);
        for (int x : a) {
            if (!seen[x]) {
                seen[x] = true;
                distinct.push_back(x);
            }
        }
    }

    if ((int)distinct.size() > k) {
        cout << -1 << el;
        return;
    }

    while ((int)distinct.size() < k) {
        distinct.push_back(distinct.back());
    }

    int m = n * k;
    cout << m << el;

    for (int i = 0; i < n; i++) {
        for (int x : distinct) {
            cout << x << " ";
        }
    }
    cout << el;
}

int main() {
    FastIO;
    int t = 1;
    cin >> t;
    while (t--) solve();
}
