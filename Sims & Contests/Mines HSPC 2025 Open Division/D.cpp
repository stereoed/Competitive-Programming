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
  string s;
  getline(cin, s);

  int o = 0;
  int start = 0;
  auto it = s.find("certainly", start);
  while (it != string::npos){
    start = it + 1;
    o++;
    it = s.find("certainly", start);
  }
  cout << o;
}

int main() {
  FastIO;
  int t = 1;
  //cin >> t;
  while (t--) solve();
  return 0;
}