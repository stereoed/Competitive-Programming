#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__)
#else
    #define dump(...)
#endif

int n, m, x, y;

void solve(){
    cin >> n >> m >> x >> y;
    vector<int> A(x), B(y);
    for (auto& r : A) cin >> r;
    for (auto& r : B) cin >> r;

    dump(n, A);
    dump(m, B);

    int row = n, col = m, comodines = 0;
    long long ans = 0, repeats = 0;

    // Fill to row - 1, col - 1, with the best instruments.
    while (row > 1 && col > 1){
        int arow = (A.size() ? A.back() : 0), bcol = (B.size() ? B.back() : 0);
        if (arow == bcol){
            if (arow == 0) break;
            repeats += arow;
            comodines++;

            A.pop_back(); row--;
            B.pop_back(); col--;
            continue;
        }

        if (arow < bcol){
            swap(arow, bcol);
            swap(A, B);
            swap(row, col);
        }

        ans += arow;
        A.pop_back(); row--;
    }

    if (row < col){
        swap(A, B);
        swap(row, col);
    }

    set<int> seen;
    while (row > 1){
        if (A.empty()) break;
        ans += A.back();
        seen.insert(A.back());
        A.pop_back(); row--;
    }

    dump(ans, repeats, comodines);
    dump(A);
    dump(B);

    for (const int r : B) A.push_back(r);
    sort(A.rbegin(), A.rend());
    A.erase(unique(A.begin(), A.end()), A.end());

    for (int i = 0; i < min((int)A.size(), comodines + 1); i++){
        if (seen.count(A[i])) {
            comodines++;
            continue;
        }
        dump(ans, A[i]);
        ans += A[i];
    }

    cout << ans + repeats << '\n';
    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;

    while (t--) {
        solve();
    }
}