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

string s;
vector<bool> is_prime(101, true), possible(101, false);
vector<int> primes;

void solve(){
    is_prime[0] = false; is_prime[1] = false;
    

    for (int i = 2; i < 101; i++){
        if (!is_prime[i]) continue;
        primes.push_back(i);

        int elim = 0;
        for (int x = 2 * i; x < 101; x += i) {
            if (is_prime[x]) elim++;
            is_prime[x] = false;
        } 
        dump(i, elim)
    }

    dump(is_prime);
    dump(primes.size(), primes)

    int q = 0, divisor = -1;
    for (const auto prime : primes){
        cout << prime << endl; fflush(stdout); q++;
        cin >> s;

        if (s == "yes"){
            for (int i = prime; i < 101; i += prime) {
                if (possible[i]){
                    cout << "composite" << endl; fflush(stdout);
                    return;
                }
                possible[i] = true;
            }

            divisor = prime;
        }

        if ((divisor != -1 && prime > 100 / divisor) || q == 20) break;
    }

    dump("nxt")

    if (divisor != -1) for (int i = divisor * divisor; i < 100; i *= divisor){
        cout << i << endl; fflush(stdout); q++;
        cin >> s;

        if (s == "yes"){
            cout << "composite" << endl; fflush(stdout);
            return;
        }

        if (q == 20) break;
    }

    cout << "prime" << endl; fflush(stdout);
    dump(possible)
}

int main() {
    FastIO;
    int t = 1; // cin >> t;
    while (t--) solve();
}