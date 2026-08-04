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
    int ans = 0;

    int prev = -1, prev_2 = -1;
    // 3 -> Cuadrado
    // 2 -> Triangulo
    // 1 -> Circulo

    for (int i = 0; i < n; i++){
        int cur; cin >> cur;
        
        if (prev == 3){
            if (cur == 2){
                cout << "Infinite" << el;
                return;
            } // Cuadrado -> Triangulo
            else ans += 4; // Cuadado -> Circulo
        }

        else if (prev == 2){
            if (cur == 3) {
                cout << "Infinite" << el;
                return;
            } // Triangulo -> Cuadrado
            else ans += 3; // Triangulo -> Circulo
        }

        else if (prev == 1){
            if (cur == 3) ans += 4; // Circulo -> Cuadrado
            else { // Cuadrado -> Circulo -> Triangulo
                if (prev_2 == 3) ans -= 1; 
                ans += 3;
            }
        }
        
        prev_2 = prev;
        prev = cur; 
    }
    
    if (ans != -1){
        cout << "Finite" << el;
        cout << ans << el;
        return;
    }
}

int main() {
    FastIO;
    int t = 1;
    while (t--) solve();
}
