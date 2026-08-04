#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

char opposite(char sign){
    if (sign == '-') return '+';
    else return '-';
}

void solve() {
    int n; cin >> n;
    set<int> ids;
    vector<int> cumsum(n + 1, 0); 
    vector<int> ans(n, 0);

    rep(i, n){
        char sign; cin >> sign;
        int id; cin >> id;
        if (sign == '+') ids.insert(id);
        else if (ids.count(id)) ids.erase(id);
        else cumsum[i]++;
        ans[i] = (int)ids.size();
    }

    for(int i = n - 1; i >= 0; i--){
        cumsum[i] += cumsum[i + 1];
    }
    int maxi = cumsum[0];
    rep(i, n){
        maxi = max(ans[i] + cumsum[i + 1], maxi);
    }
    cout << maxi << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}