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
string s1, s2;

void solve() {
    cin >> s1 >> s2;
    bool automaton = false, array = false;
    vector<vector<int>> cnt (2, vector<int>(27));
    for (const char c : s1) cnt[0][c - 'a']++;
    for (const char c : s2) cnt[1][c - 'a']++;

    for (int i = 0; i < 27; i++){
        // Tengo que agregar letras
        if (cnt[0][i] < cnt[1][i]){
            cout << "need tree" << el;
            return; 
        }

        // Tengo que eliminar letras
        if (cnt[0][i] > cnt[1][i]){
            automaton = true;
        }
    }

    // Debo reordenar?
    int ptr_1 = 0, ptr_2 = 0;
    while(ptr_1 < s1.size() && ptr_2 < s2.size()){
        if (s1[ptr_1] == s2[ptr_2]) ptr_2++;
        ptr_1++;
    }

    array = ptr_2 != s2.size();
    if (automaton){
        if (array){
            cout << "both" << el;
            return;
        }
        cout << "automaton" << el;
        return;
    }

    cout << "array" << el;
}

int main() {
    FastIO;
    int t = 1; //cin >> t;
    while (t--) solve();
}
