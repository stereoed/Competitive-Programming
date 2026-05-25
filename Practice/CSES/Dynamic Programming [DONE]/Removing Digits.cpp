#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repb(i, n) for (int i = (int)n-1; i >= 0; i--)
#define repx(i, a, n) for (int i = (int)a; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define el "\n"
const int MOD = 1e9 + 7;
const int INF = 1e9;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
 
    vi dp(n + 1, INF);
    dp[n] = 0;
 
    repb(i, n+1){
        int copy = i;
        if (dp[i] == INF) continue;
        
        while (copy){
            dp[i - copy%10] = min(dp[i - copy%10], dp[i] + 1);
            copy /= 10;
        }
    }
 
    cout << dp[0] << "\n";
}