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
    int n, m; cin >> n >> m;
    vector<int> a(n), b(n); a[0] = 1;
    for (int i = 1; i < n; i++) cin >> a[i]; 
    sort(a.begin(), a.end()); dump(a);

    for (int i = 0; i < n; i++) cin >> b[i]; 
    sort(b.begin(), b.end()); dump(b);

    int la = 0, ans = 0;
    for (int lb = 0; lb < n; lb++){
        if (b[lb] <= a[la]) ans++;
        else la++;
    }

    cout << ans << '\n';    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}