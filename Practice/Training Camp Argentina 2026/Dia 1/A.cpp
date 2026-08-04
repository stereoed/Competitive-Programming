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
    vector<vector<int>> adj(n);
    vector<int> match(n);

    set<int> left;

    for (int i = 1; i <= n; i++){
        left.insert(i);
    }

    for (int i = 0; i < n; i++){
        int k; cin >> k;
        for (int j = 0; j < k; j++){
            int a; cin >> a;
            adj[i].push_back(a);
        }
    }

    dump(adj)

    for (int i = 0; i < n; i++){
        for (const auto prince : adj[i]){
            auto it = left.find(prince);

            if (it != left.end()){
                match[i] = prince;
                left.erase(it);
                break;
            }
        }
    }

    dump(match)

    for (int i = 0; i < n; i++){
        if (match[i] == 0){
            cout << "IMPROVE" << el;
            cout << i + 1 << " " << *left.begin() << el;
            return;
        }
    }

    cout << "OPTIMAL"<< el;
}

int main() {
	FastIO;
    
	int t = 1;
	cin >> t;
	
	while (t--) solve();
}