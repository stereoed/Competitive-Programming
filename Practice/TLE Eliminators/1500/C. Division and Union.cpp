#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

void solve() {
    int n; cin >> n;
    vector<pair<pair<int, int>, int>> A(n);
    vector<int> color(n, -1);
    rep(i, n) {
        cin >> A[i].first.first >> A[i].first.second;
        A[i].second = i;
    }
    sort(A.begin(), A.end());
    color[A[0].second] = 0;
    int max_r = A[0].first.second;

    bool solvable = false;
    repk(i, 1, n){
        if (A[i].first.first > max_r) {
            color[A[i].second] = !color[A[i - 1].second];
            solvable = true;
        } else color[A[i].second] = color[A[i - 1].second];
        max_r = max(max_r, A[i].first.second);
    }
    if (!solvable) cout << -1 << endl;
    else {
        rep(i, n) cout << color[i] + 1 << ' ';
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}