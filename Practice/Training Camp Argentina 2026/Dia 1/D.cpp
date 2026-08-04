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
vector<int> a;

void solve() {
    cin >> n;
    a = vector<int>(n);

    /*
    * Me conviene dividir el mas grande
    * Me conviene multiplicar el mas chico
    * Pruebo todos los divisores del mas grande
    */ 

    int smallest = 1e9, sum = 0;
    for (auto& x : a){
        cin >> x;

        sum += x;
        smallest = min(smallest, x);
    } 

    dump(smallest)
    int ans = sum;

    for (const int biggest : a){
        for (int i = 1; i < biggest; i++){
            if (biggest % i) continue;

            int new_small = smallest * i;
            int new_big = biggest / i;
            int var = new_small - smallest + new_big - biggest;
            dump(i, new_small, new_big, var)

            ans = min(ans, sum + var);
        }
    }

    cout << ans << el;
}

int main() {
	FastIO;
    
	int t = 1;
	//cin >> t;
	
	while (t--) solve();
}