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
    int n; cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];

    vector<int> ans(n + 1, 1);
    int final_ans = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 2 * i; j <= n; j += i){
            if (v[i] < v[j]) ans[j] = max(ans[j], ans[i] + 1);
            final_ans = max(final_ans, ans[j]);
        }
    }

    cout << final_ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}