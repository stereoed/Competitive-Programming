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

void solve() {
    cin >> n >> s;
    int left = 0, right = n - 1, ans = -1;
    vector<char> to_test;
    //cout << s << '\n';

    while (left < right){
        if (s[left++] == s[right--]) continue;
        to_test.push_back(s[left - 1]);
        to_test.push_back(s[right + 1]);
        break;
    }

    if (to_test.empty()){
        cout << "0\n";
        return;
    }

    left--; right++;
    for (char c : to_test){
        //cout << c << '\n';
        int l = left, r = right, ass = 0;
        while (l < r){
            if (s[l++] == s[r--]) continue;
            //cout << "mismatch: " << l - 1 << " " << r + 1 << '\n';
            //cout << s[l-1] << " " << s[r+1] << '\n';
            const char a = s[l - 1], b = s[r + 1];
            ass++;
            
            if (c == a) r++;
            else if (c == b) l--;
            else {
                ass = -1;
                break;
            }
        }

        //cout << ass << " " << ans << '\n';
        if (ass != -1){
            if (ans == -1) ans = ass;
            else ans = min(ans, ass);
        }
    }

    cout << ans << '\n';
}

int main() {
    FastIO;
    int t = 1; cin >> t;
    while (t--) solve();
}