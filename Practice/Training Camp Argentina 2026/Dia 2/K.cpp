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

int n, ans;
string s;

void solve() {
    cin >> n >> s;
    dump(s)

    int vturns = (n - 11) / 2;
    string aux;

    for (const auto x : s){
        if (vturns && x != '8'){
            vturns--;
            continue;   
        }
        aux.push_back(x);
    }

    dump(aux);

    bool all = true;
    for (int i = 0; i < aux.size() - 10; i++){
        if (aux[i] != '8') all = false;
    }


    cout << (all ? "YES" : "NO") << el;

}

int main() {
    FastIO;
    int t = 1;
    //cin >> t;
    while (t--) solve();
}
