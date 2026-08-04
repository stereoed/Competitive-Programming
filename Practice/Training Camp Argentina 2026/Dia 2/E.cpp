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

long long n, m;
vector<vector<long long>> mat;


pair<long long, long long> ok(long long mid){
    map<int8_t, vector<long long>> seen;
    vector<int8_t> nugget;

    for (long long x = 0; x < n; x++){
        int8_t bm = 0;

        for (long long i = 0; i < m; i++){
            if (mat[x][i] >= mid) bm |= (1 << i);
        }

        dump(bm)
        if (!seen.count(bm)) nugget.push_back(bm);
        seen[bm].push_back(x);
    }

    dump(nugget);

    int8_t TC = 0; // Que estan todos completos
    for (long long i = 0; i < m; i++){
        TC |= (1 << i);
    }

    for (const auto line : nugget){
        for (const auto line_2 : nugget){
            if ((line | line_2) == TC){
                return {seen[line][0], seen[line_2][0]};
            } 
        }
    }

    return {-1, -1};
    
}

void solve() {
    cin >> n >> m;
    mat = vector<vector<long long>>(n, vector<long long>(m));

    for (auto& line : mat){
        for (auto& x : line){
            cin >> x;
        }
    }

    dump(n, m)
    dump(mat)

    long long l = -1, r = 2e9;
    long long one = -1, two = -1;
    while (l < r) {
        long long mid = l + (r - l + 1) / 2;
        dump(l, r, mid);

        auto [a, b] = ok(mid);
        if (a != -1) {
            l = mid;
            one = a; two = b;
        } else {
            r = mid - 1;
        }
    }

    cout << one + 1 << " " << two + 1 << el;
}

int main() {
    FastIO;
    solve();
}
