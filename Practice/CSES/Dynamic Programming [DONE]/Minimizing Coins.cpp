#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, x;
    cin >> n >> x;
    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];
 
    const int INF = 1e9;
    vector<int> dist(x + 1, INF);
    queue<int> q;
 
    dist[0] = 0;
    q.push(0);
 
    while (!q.empty()) {
        int s = q.front(); q.pop();
        int d = dist[s];
 
        for (int coin : c) {
            int ns = s + coin;
            if (ns > x) continue;
            if (dist[ns] != INF) continue;
            dist[ns] = d + 1;
            q.push(ns);
        }
    }
 
    cout << (dist[x] == INF ? -1 : dist[x]) << "\n";
}