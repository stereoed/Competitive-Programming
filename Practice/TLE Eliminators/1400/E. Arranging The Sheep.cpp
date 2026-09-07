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

    vector<int> pos;
    for (int i = 0; i < n; i++) if (s[i] == '*') pos.push_back(i);

    n = pos.size();
    if (n <= 1){
        cout << "0\n";
        return;
    }

    int turn_point = n / 2;
    int median = pos[turn_point];

    long long ans = 0;
    for (int i = 0; i < turn_point; i++){
        ans += median - (turn_point - i) - pos[i];
    }

    for (int i = turn_point + 1; i < n; i++){
        ans += pos[i] - (median + (i - turn_point));
    }

    cout << ans << '\n';    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}