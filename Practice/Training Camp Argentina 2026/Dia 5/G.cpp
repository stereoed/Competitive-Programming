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

int n;
void solve() {
    int s[6];
    
    int base = 0, bid = 0;
    for (int i = 0; i < 6; i++){
        cin >> s[i];
        if (s[i] > base){
            base = s[i];
            bid = i;
        }
    } 

    base += s[(bid + 1) % 6] + s[(bid + 5) % 6];
    dump(base, bid, s);

    int ans = base * base; dump(ans); // Triangle area
    ans -= s[(bid + 1) % 6] * s[(bid + 1) % 6]; dump(ans); // minus left nip
    ans -= s[(bid + 5) % 6] * s[(bid + 5) % 6]; dump(ans); // minus righs nip
    ans -= s[(bid + 3) % 6] * s[(bid + 3) % 6]; dump(ans); // minus top nip

    cout << ans << el;
}

int main() {
    FastIO;
    int t = 1; //cin >> t;
    while (t--) solve();
}