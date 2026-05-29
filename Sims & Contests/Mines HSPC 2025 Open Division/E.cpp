#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define el '\n'
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repx(i, a, n) for (int i = (int)a; i < (int)(n); i++)
#define pb push_back
#define all(v) v.begin(), v.end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;


// Arbol de cobertura minima
// Algoritmo de krustal

// Dsu
vector<ll> s;
vector<vector<int>> v;
vector<bool> inSet;

void solve() {
    ll p, t;
    cin >> p >> t;
    string s;
    cin >> s;

    const int INF = 1e9;
    int n = (int)s.size();
    vector<int> dist(n, INF);

    int last = -1;
    rep(i, n) {
        if (s[i] == 'W') {
          last = -1;
        } else if (s[i] == 'I') {
          dist[i] = 0;
          last = i;
        } else if (last != -1) {
          dist[i] = i - last;
        }
    }

    last = -1;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == 'W') {
            last = -1;
        } else if (s[i] == 'I') {
            dist[i] = 0;
            last = i;
        } else if (last != -1) {           // s[i] == 'H'
            dist[i] = min(dist[i], last - i);
        }
    }

    ll worst = -1;                         // longest time any healthy needs to get infected
    rep(i,n) {
        if (s[i] == 'H') {
            if (dist[i] == INF) {          // segment without infection
              cout << "CURED" << el;
              return;
            }
            worst = max(worst, 1LL * dist[i] * p);
        }
    }

    if (worst >= t) cout << "CURED" << el;
    else            cout << "ALL INFECTED" << el;
}
  

int main() {
  FastIO;
  int t = 1;
  //cin >> t;
  while (t--) solve();
  return 0;
}