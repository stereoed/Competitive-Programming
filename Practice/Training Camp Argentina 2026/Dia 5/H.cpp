#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__)
#else
    #define dump(...)
#endif

int n, m;
vector<string> grid;
vector<vector<pair<int, int>>> reachable;
vector<pair<int, int>> delta = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void solve(){
    cin >> n >> m;
    grid = vector<string>(n); for (auto& s : grid) cin >> s;
    reachable.assign(n, vector<pair<int, int>>(m, {-1, -1}));

    pair<int, int> start;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (grid[i][j] == 'S'){
                start = {i, j};
            }
        }
    }

    queue<pair<int, int>> q;
    q.push(start);
    reachable[start.first][start.second] = start;

    while (!q.empty()){
        const auto [i, j] = q.front(); q.pop(); dump(i, j);

        for (const auto [di, dj] : delta){
            const int ni = (((i + di) % n) + n) % n, nj = (((j + dj) % m) + m) % m; 
            if (grid[ni][nj] == '#') continue; 

            if (reachable[ni][nj] != pair<int, int>{-1, -1}){ // Visto
                dump(reachable[ni][nj], ni, nj, reachable[ni][nj].first == i + di && reachable[ni][nj].second == j + dj);
                if (reachable[ni][nj].first == i + di && reachable[ni][nj].second == j + dj) continue;
                cout << "YES\n";
                return;
            }

            reachable[ni][nj] = {i + di, j + dj};
            q.push({i + di, j + dj});
        }
    }
    cout << "NO\n"; 
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;

    while (t--) {
        solve();
    }
}
