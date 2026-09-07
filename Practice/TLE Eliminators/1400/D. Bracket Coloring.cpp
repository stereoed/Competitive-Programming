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
    string s; cin >> s;

    int cnt = 0;
    vector<int> ans(n, 1);

    bool two = false;
    bool was_one = false;
    for (int i = 0; i < n; i++){
        cnt += (s[i] == '(' ? 1 : -1);

        if (cnt < 0) two = true;
        if (cnt > 0) two = false;
        was_one |= !two;

        ans[i] = (two ? 2 : 1);
    }

    if (cnt != 0) {
        cout << "-1\n";
        return;
    }

    if (!was_one){
        for (int i = 0; i < n; i++) ans[i]--;
    }

    cout << *max_element(ans.begin(), ans.end()) << '\n';
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}