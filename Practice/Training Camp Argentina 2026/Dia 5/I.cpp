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

int r, c, k;

void solve() {
    cin >> r >> c >> k;

    string chickens;
    for (int i = 0; i < k; i++) {
        if (i < 10) chickens += char('0' + i);
        else if (i < 36) chickens += char('A' + (i - 10));
        else chickens += char('a' + (i - 36));
    }
    dump(chickens)

    vector<vector<int>> grid(r, vector<int>(c));
 
    int rice = 0;
    for (auto& line : grid){
        for (auto& x : line){
            char ch; cin >> ch;
            x = ch == 'R';
            rice += x;
        }
    }

    int rpc = rice / k;
    int special = rice % k;

    int ptr = 0;
    int rem = rpc + (ptr < special);
    int modifier = 1;
    int j = 0;
    for (int i = 0; i < r; i++) {
        j = max(0, min(j, c - 1));

        string s;
        while (j >= 0 && j < c) {
            s += chickens[ptr];

            if (grid[i][j]){
                rem--;
                if (rem == 0 && ptr < k - 1) {
                    ptr++;
                    rem = rpc + (ptr < special);
                }
            }

            j += modifier;
        }

        if (modifier < 0) reverse(all(s));
        modifier = -modifier;
        cout << s << el;
    }
}


int main() {
    FastIO;
    int t = 1; cin >> t;
    while (t--) solve();
}
