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



void solve() {
  string s;
  int n;
  cin >> s >> n;

  vector<pair<string, string>> rules(n);
  rep(i, n){
    string a;
    cin >> a;

    auto it = a.find("=");
    rules[i] = {a.substr(0, it), a.substr(it + 1)};
  }

  rep(i, 5000){
    bool flag = false;
    rep(i, n){
      auto it = s.find(rules[i].first);

      if (it != string::npos){
        s = s.substr(0, it) + rules[i].second + s.substr(it + rules[i].first.size());
        //cerr << s.size() << el;
        flag = true;

        if (s.size() > 255){
          cout << "Memory Limit Exceeded" << el;
          return;
        }

        break;
      }
    }

    if (!flag) {
      cout << s << el;
      return;
    }
  }

  for (int j = 0; j < n; ++j) {
    if (s.find(rules[j].first) != string::npos) {
      cout << "Time Limit Exceeded" << el;
      return;
    }
  }
  cout << s << el;
}

int main() {
  FastIO;
  int t = 1;
  //cin >> t;
  while (t--) solve();
  return 0;
}