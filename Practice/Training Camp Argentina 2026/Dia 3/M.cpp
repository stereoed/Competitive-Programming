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


int n;
void solve() {
    cin >> n;

    vector<int> a(n);
    for (auto& x : a) cin >> x;

    int x = 1;
    int rnd = 0;

    int mi = 1e9, ma = 0;
    for (int i = n - 1; i >= 0; i--){
        ma = max(ma, a[i] - mi);
        mi = min(mi, a[i]);
    }

    dump(ma)

    int z = 0;
    while (z < ma){
        z += x;
        x *= 2;
        rnd++;
    }

    cout << rnd << el;
}

int main() {
	FastIO;
    
	int t = 1;
	cin >> t;
	
	while (t--) solve();
}