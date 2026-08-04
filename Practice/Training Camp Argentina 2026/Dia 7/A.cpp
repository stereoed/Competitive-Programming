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

double n, h;

bool ok(double cut, double area){
    // h / 1 == cut / base -> base = cut / h; Area = cut * cut / h;
    dump(area, (cut * cut / h), area <= (cut * cut / h));
    return (area <= (cut * cut / h));
}

const double eps = 1 / 1e7;
void solve(){
    cin >> n >> h;
    double area = h / n; dump(area);

    for (int i = 1; i < n; i++){
        double l = 0, r = h;
        double target = i * area;

        while (r - l >= eps){
            double mid = l + (r - l)/2;
            dump(l, r, mid);
            
            if (ok(mid, target)) r = mid;
            else l = mid;
        }

        cout << setprecision(8) << l << " ";
    }

    cout << el;
}

int main() {
    FastIO;
    int t = 1; //cin >> t;
    while (t--) solve();
}