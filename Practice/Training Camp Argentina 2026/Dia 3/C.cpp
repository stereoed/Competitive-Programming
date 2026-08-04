#pragma GCC optimize("Ofast")
using namespace std;

#if __has_include("stdc++.h")
    #include "stdc++.h"
#else
    #include <bits/stdc++.h>
#endif

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(v) v.begin(), v.end()
#define el '\n'

int n, m, k;
vector<string> mat;

bool in(int x, int y){
    if (x < 0 || y < 0) return false;
    if (x >= n || y >= m ) return false;
    return mat[x][y] == 'X';
}

vector<pair<int, int>> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void bfs(int e, int t, int rem){
    queue<pair<int, int>> q;
    q.push({e, t});

    mat[e][t] = '.';
    rem--;

    while (!q.empty() && rem > 0){
        auto [x, y] = q.front(); q.pop();

        for (const auto [dx, dy] : moves){
            int nx = x + dx;
            int ny = y + dy;

            if (!in(nx, ny)) continue;

            mat[nx][ny] = '.';
            rem--;

            if (rem == 0) break;

            q.push({nx, ny});
        }
    }
}

void solve() {
    cin >> n >> m >> k;
    mat = vector<string>(n);
    int rem = 0;
    for (auto& s : mat) {
        cin >> s;
        for (auto& c : s) if (c == '.') {
            c = 'X';
            rem++;
        }
    }

    bool flag = false;
    rem -= k;
    dump(k, rem)

    for (int i = 0; i < n; i++) {
        for (int x = 0; x < m; x++) if (mat[i][x] == 'X') {            
            bfs(i, x, rem);
            
            flag = true;
            break;
        }
        if (flag) break;
    }

    for (const auto qq : mat) cout << qq << el;
}

int main() {
    FastIO;
    int t = 1; // cin >> t;
    while (t--)
    solve();
}