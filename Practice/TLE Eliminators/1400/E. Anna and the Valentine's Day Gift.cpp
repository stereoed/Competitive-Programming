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
    long long n, m; cin >> n >> m;

    long long sum = 0;
    vector<int> zeroes;
    for (int i = 0; i < n; i++){
        string s; cin >> s;
        int x = s.size();
        sum += x;

        int cnt = 0;
        while (s[x - cnt - 1] == '0') cnt++;
        zeroes.push_back(cnt);
    }
    sort(zeroes.rbegin(), zeroes.rend());
    dump(sum, zeroes);
    
    int x = zeroes.size();
    for (int i = 0; i < x; i += 2) sum -= zeroes[i];
    dump(sum);

    cout << (sum > m ? "Sasha" : "Anna") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}