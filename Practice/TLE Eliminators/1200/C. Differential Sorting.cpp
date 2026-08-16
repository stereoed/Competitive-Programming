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
string s;
char c;

void solve() {
    cin >> n >> c >> s;
    vector<bool> different(n);
    int cnt_different = 0;

    for (int i = 0; i < n; i++){
        different[i] = s[i] != c;
        cnt_different += s[i] != c;
    }

    // ZERO
    if (cnt_different == 0){
        cout << "0\n";
        return;
    }

    // ONE
    for (int i = n/2; i < n; i++){
        if (s[i] == c){
            cout << "1\n " << i + 1 << '\n';
            return;
        }
    }

    // TWO
    cout << "2\n " << n << " " << n-1 << '\n';
}

int main() {
    FastIO;
    int t = 1; cin >> t;
    while (t--) solve();
}