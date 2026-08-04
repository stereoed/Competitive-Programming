#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

void solve() {
    int n; cin >> n;
    map<char, int> cards;
    vector<char> possible = {'B', 'G', 'R'};
    string s; cin >> s;
    
    rep(i, n) {
        char c = s[i];
        cards[c]++;
    }

    int size = (int)cards.size();
    if (size == 1){
        for(auto [c, x] : cards) cout << c << endl;
    } else if ((size == 2)){
        int mini = 200;
        int maxi = 0;
        char letramax, letramin;
        for(auto [c, x] : cards){
            if (x < mini){
                letramin = c;
                mini = x;
            }
            if (x > maxi){
                letramax = c;
                maxi = x;
            }
        }
        if (mini == 1 && maxi == 1){
            for(char c : possible){
                if (!cards[c]){
                    cout << c << endl;
                }
            }
        } else if (mini == 1 && maxi > 1){
            for(char c : possible){
                if (c != letramax) cout << c;
            }
            cout << endl;
        } else if (mini > 1 && maxi > 1){
            cout << "BGR" << endl;
        }
        
    } else if (size == 3){
        cout << "BGR" << endl;
    }
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