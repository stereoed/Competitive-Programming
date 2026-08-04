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
    cin >> n;

    if (n < 4){
        cout << "NO" << el;
        return;
    } 

    cout << "YES" << el;
    int counter = 0;
    if (n % 2 == 0){
        counter = 1;
        cout << "2 * 3 = 6" << el;
        cout << "6 * 4 = 24" << el;
        for (int i = 5; i <= n; i += 2){
            cout << i + 1 << " - " << i << " = " << 1 << el;
            counter++;
        }
    } else {
        cout << "5 * 3 = 15" << el;
        cout << "2 * 4 = 8" << el;
        cout << "15 + 8 = 23" << el;
        cout << "23 + 1 = 24" << el;
        
        for (int i = 6; i <= n; i += 2){
            cout << i + 1 << " - " << i << " = " << 1 << el;
            counter++;
        }
    }

    for (int i = 0; i < counter; i++){
        cout << 24 << " * " << 1 << " = " << 24 << el;
    }
}

int main() {
    FastIO;
    int t = 1; //cin >> t;
    while (t--) solve();
}
