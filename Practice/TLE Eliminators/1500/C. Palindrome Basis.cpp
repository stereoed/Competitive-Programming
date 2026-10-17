#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

const int M = 1000000007;
const int MAXN = 40005;

long long dp[MAXN]{};
vector<int> coins;

bool is_palindrome(int x){
    string aux = to_string(x);
    int n = aux.size();

    for (int l = 0; l < n / 2; l++) if (aux[l] != aux[n - l - 1]) return false;
    return true;
}

void solve(){
    int n; cin >> n;
    cout << dp[n] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    for (int i = 1; i < MAXN; i++){
        if (is_palindrome(i)) coins.push_back(i);
    }

    dp[0] = 1;
    for (auto c : coins){
        for (int i = 0; i < MAXN; i++){
            if (i + c < MAXN) dp[i + c] = (dp[i + c] + dp[i]) % M;
        }
    }

    int t = 1; cin >> t;
    while (t--) solve();
}