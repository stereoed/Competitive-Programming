#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

vector<int> x = {4, 8, 15, 16, 23, 42};
int p12, p23, p34, p5;

vector<int> ans;
bool dfs(int used, int len){
    if (len == 2 && p12 != ans[0] * ans[1]) return false;
    if (len == 3 && p23 != ans[1] * ans[2]) return false;
    if (len == 4 && p34 != ans[2] * ans[3]) return false;
    if (len == 5 && p5 != ans[4] * ans[4]) return false;
    if (len == 6) return true;
    dump(ans);

    for (int i = 0; i < 6; i++){
        if (used & (1 << i)) continue;

        ans.push_back(x[i]);
        if (dfs(used | (1 << i), len + 1)) return true;
        ans.pop_back();
    }

    return false;
}

void solve(){
    
    cout << "? 1 2 \n? 2 3 \n? 3 4 \n? 5 5" << std::endl;
    fflush(stdout);

    cin >> p12 >> p23 >> p34 >> p5;
    std::ignore = dfs(0, 0);

    cout << "! ";
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
}