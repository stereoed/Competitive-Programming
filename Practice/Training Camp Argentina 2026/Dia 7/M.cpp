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

long long n;

// Pinpinhao
void print_int128(__int128_t n) {
    if (n == 0) {
        std::cout << '0';
        return;
    }

    bool negative = n < 0;
    if (negative) n = -n;

    std::string s;
    while (n > 0) {
        s += char('0' + (int)(n % 10));
        n /= 10;
    }

    if (negative) s += '-';
    std::reverse(s.begin(), s.end());
    std::cout << s;
}

void solve(){
    cin >> n; dump(n);
    map<long long, long long> freq;

    __int128_t sum = 0, ans = 0;
    for (long long i = 0; i < n; i++){
        long long x; cin >> x;
        freq[x]++;
        
        __int128_t local = i * x - sum; 
        
        local += freq[x + 1];   
        local -= freq[x - 1];

        ans += local;
        sum += x;
    }

    print_int128(ans);
}

int main() {
    FastIO;
    int t = 1; //cin >> t;
    while (t--) solve();
}