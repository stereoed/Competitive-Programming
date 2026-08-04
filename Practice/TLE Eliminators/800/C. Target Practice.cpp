#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__)
#else
    #define dump(...)
#endif

int n, m;
vector<int> v;
string s, s1, s2;

void solve(){
    int sum = 0;

    for (int i = 1; i <= 10; i++){
        cin >> s;
        for (int j = 1; j <= 10; j++){
            if (s[j-1] == '.') continue;
            int max_score = (i > 5 ? 10 - i + 1 : i);
            int x = (j > 5 ? 10 - j + 1 : j); 
            sum += min(max_score, x);
        }
    }

    cout << sum << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;

    while (t--) {
        solve();
    }
}
