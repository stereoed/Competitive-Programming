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


int n, g, b;
void solve() {
    cin >> n >> g >> b;
    long long needed = (n + 1)/2;
    long long ans = needed;
    
    ans += (needed / g) * b;
    if (needed % g == 0) ans -= b;

    cout << max<long long>(n, ans) << el;
}

int main() {
	FastIO;
    
	int t = 1;
	cin >> t;
	
	while (t--) solve();
}