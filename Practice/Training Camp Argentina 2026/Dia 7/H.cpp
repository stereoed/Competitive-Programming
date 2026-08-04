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
#define repf(i,k,n) for(int i=k; i<n; i++)
#define rep(i,n) for(int i=0; i<n; i++)
#define el '\n'

int n, m;
string s;

void solve(){
    cin >> n >> m;
    map<string, int> stoid;
    int id = 0;

    //// INPUT ////
    vector<vector<bool>> incompatible(m, vector<bool>(m));
    vector<int> segment;

    for (int i = 0; i <= n; i++){
        int a = 1;
        // Una iteracion mas para no repetir codigo despues
        if (i < n) cin >> a;
        
        if (a == 1){
            // Sorteo y borro los duplicados
            sort(all(segment));
            auto it = unique(all(segment));
            segment.erase(it, segment.end());

            // Marco como incompatibles los elementos del segmento
            int sz = segment.size();
            for (int x = 0; x < sz; x++){
                for (int y = x + 1; y < sz; y++){
                    incompatible[segment[x]][segment[y]] = true;
                    incompatible[segment[y]][segment[x]] = true;
                }
            }

            // Borro el segmento para empezar de nuevo a agrupar
            segment.clear();
            continue;
        }

        cin >> s;

        // Le asigno un id unico a cada nombre, chao strings
        if (!stoid.count(s)) stoid[s] = id++;
        int local_id = stoid[s];

        // Meto al segmento actual
        segment.push_back(local_id);
    }

    // dump(incompatible);
    //// Maximum Independent Set & Meet in the Middle ////

    /// BUILDING ///

    int s1 = m/2, s2 = m - s1;
    vector<int> left(1 << s1), right(1 << s2);

    // Left side build
    for (int bm = 0; bm < (int)left.size(); bm++){ // O(2^20)
        for (int added = 0; added < s1; added++){ // O(20)
            int new_bm = bm | (1 << added);
            if (bm == new_bm) continue; // Repeat; Ignore.

            // Assumme possible, check for incompatibilities
            int possible = true; 
            for (int current = 0; current < s1; current++){ // O(20)
                if ((bm >> current)&1) possible &= !(incompatible[current][added]);
            }

            // If possible, save the best result.
            if (left[bm] >= 0 && possible) left[new_bm] = max(left[new_bm], left[bm] + 1);
            else left[new_bm] = min(left[new_bm], -abs(left[bm]));
        }
    }

    // Right side
    for (int bm = 0; bm < (int)right.size(); bm++){ // O(2^20)
        for (int added = 0; added < s2; added++){ // O(20)
            int new_bm = bm | (1 << added);
            if (bm == new_bm) continue; // Repeat; Ignore.

            // Assumme possible, check for incompatibilities
            int possible = true; 
            for (int current = 0; current < s2; current++){ // O(20)
                if ((bm >> current)&1) possible &= !(incompatible[current + s1][added + s1]);
            }

            // If possible, save the best result.
            if (right[bm] >= 0 && possible) right[new_bm] = max(right[new_bm], right[bm] + 1);
            else right[new_bm] = min(right[new_bm], -abs(right[bm]));
        }
    }

    dump(left);
    dump(right);

    /// Combination ///
    int ans = 0;

    for (int bm = 0; bm < (int)left.size(); bm++){ // O(2^20)
        if (left[bm] < 0) continue;
        int new_bm = (1 << s2) - 1;

        // Agrego todos los que son compatibles con el lado derecho.
        for (int current = 0; current < s1; current++){ // O(20)
            if (((bm >> current) & 1) == 0) continue;

            for (int added = 0; added < s2; added++){ // O(20)
                new_bm &= ~(incompatible[current][s1 + added] << added);
            }
        }

        ans = max(ans, left[bm] + abs(right[new_bm]));
        dump(bm, new_bm, left[bm], abs(right[new_bm]), ans)
    }

    //// OUTPUT ////
    cout << ans << el;
    return;

    cout << "Queria darle las gracias al olor a pata que hay en esta pieza por motivarme a terminar la wea rapida y salir " << endl;
}

int main() {
    FastIO;
    int t = 1; //cin >> t;
    while (t--) solve();
}