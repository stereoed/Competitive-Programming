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

/*
Tengo dos ideas, la primera es una dp de la mitad a la que intentamos llegar,
la segunda una dp de l, e intentamos el r mas corto para que sean iguales.
Como siempre intentaremos quitar r si ya tenemos una solucion, estamos.
*/

void solve() {
    int n; cin >> n;
    vector<int> a(2*n);
    int dif = 0;
    for (int& x : a) {
        cin >> x;
        dif += (x == 1 ? 1 : -1);
    }

    map<int,int> difr;
    difr[0] = 0;
    int cur = 0;

    for (int i = n; i < 2*n; ++i) {
        cur += (a[i] == 1) ? 1 : -1;
        if (!difr.count(cur))
            difr[cur] = i - (n - 1);
    }

    int ans = 2*n;
    if (difr.count(dif)) ans = difr[dif];

    cur = 0;
    for (int i = n - 1; i >= 0; --i) {
        cur += (a[i] == 1) ? 1 : -1;
        if (difr.count(dif - cur))
            ans = min(ans, (n - i) + difr[dif - cur]);
    }
    
    cout << ans << el;
}


int main() {
    FastIO;
    int t = 1; cin >> t;
    while (t--) solve();
}