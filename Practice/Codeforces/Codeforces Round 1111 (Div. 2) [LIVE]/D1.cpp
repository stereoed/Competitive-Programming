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

void solve() {
    int n, q; cin >> n >> q;
    vector<int> v(n);
    for (auto& x : v) cin >> x;

    if (is_sorted(all(v))){
        cout << 0 << el;
        return;
    }

    for (int w = 1; ; w *= 2){ // w -> window
        for (int i = 0; i < n; i += w * 2) {
            sort(v.begin() + i, v.begin() + min(i + w * 2, n));
        }

        if (is_sorted(all(v))){
            cout << w << el;
            return;
        }
    }    
}

int main() {
	FastIO;
    
	int t = 1;
	cin >> t;
	
	while (t--) solve();
}