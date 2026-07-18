#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int t; cin >> t;
  while (t--){
    int n; cin >> n;
    
    long long ans = 0, singles = 0, spots = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if (x > 1){
            spots += x/2 - 1;
            ans += x;
        } else singles++;
    }
    
    if (singles == n-1) spots = ans/2;
    ans += min(singles, spots);
    
    if (ans < 3) ans = 0;
    cout << ans << endl;
  }
}
