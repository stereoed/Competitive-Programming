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
vector<bool> valid(1005);
vector<vector<int>> dices;

void dfs(int dice, int value, vector<bool>& used){
    dump(dice, value, used)
    dump(dices[dice])

    for (const auto face : dices[dice]){
        int new_value = value * 10 + face;
        dump(new_value)

        valid[new_value] = 1;

        for (int i = 0; i < n; i++){
            if (used[i]) continue;
            
            used[i] = 1;
            dfs(i, new_value, used);
            used[i] = false;
        }        
    }
}

void solve() {
    cin >> n;
    dices = vector<vector<int>>(n, vector<int>(6));

    for (auto& dice : dices){
        for (auto& face : dice){
            cin >> face;
        }
    }

    dump(dices)
    for (int i = 0; i < n; i++){
        vector<bool> aux(n);
        aux[i] = 1;

        dfs(i, 0, aux);
    }


    dump(valid)
    for (int i = 1; i < 1001; i++ ){
        if (!valid[i]){
            cout << i - 1 << el;
            return;
        }
    }
}

int main() {
	FastIO;
    
	int t = 1;
	//cin >> t;
	
	while (t--) solve();
}