#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<ll> vi;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ms(arr, val) memset(arr, val, sizeof(arr))

bool bk(vi& v, vector<vi>& dp, int state, int a, int m){
    if (state == 0) return 1;
    if (dp[state][a] != -1) return dp[state][a];
    
    bool flag = 0;
    rep(i, m){
        if (!(state & (1 << i)) || v[i] % a != 0) continue;
        
        ll prev = v[i] / a;
        if (prev < 1 || prev > 100) continue;
        
        flag |= bk(v, dp, state ^ (1 << i), prev, m);
    }
    
    dp[state][a] = flag;
    return flag;
}

int main() {
    FastIO;

    int n; cin >> n;
    int m = n - 1;
    vi v(m); rep(i, m) cin >> v[i];
    
    vector<vi> dp(1 << m, vi(101, -1));
    
    int state = (1 << m) - 1;
    int last = -1;
    
    for (int a = 1; a <= 100; a++){
        if (bk(v, dp, state, a, m)){
            last = a;
            break;
        }
    }
    
    if (last == -1){
        cout << "No";
        return 0;
    }
    
    cout << "Yes" << endl;
    vi ans;
    ans.push_back(last);
    
    int cur = last;
    while (state){
        rep(i, m){
            if (!(state & (1 << i)) || v[i] % cur != 0) continue;
            
            ll prev = v[i] / cur;
            if (prev < 1 || prev > 100) continue;
            
            if (bk(v, dp, state ^ (1 << i), prev, m)){
                ans.push_back(prev);
                state ^= (1 << i);
                cur = prev;
                break;
            }
        }
    }
    
    reverse(ans.begin(), ans.end());
    for (auto a : ans) cout << a << " ";
}