#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
#include "cpp-dump.hpp"
#define dump(...) cpp_dump(__VA_ARGS__);
#else
#define dump(...)
#endif

vector<pair<int, int>> Dominoes;
vector<vector<int>> Edges;
vector<bool> A, B;
bool bad;

bool test(bool is_A, int fa, int fb){
    dump(fa, fb);

    auto& C = (is_A ? A : B);
    dump(C);

    if (C[fa] || C[fb]) return true;
    C[fa] = true;
    C[fb] = true;

    int id_a = -1;
    int a1{}, b1{};
    if (Edges[fa].size()){
        id_a = Edges[fa].back();
        Edges[fa].pop_back();
        
        if (Dominoes[id_a] == make_pair(0, 0) && Edges[fa].size()){
            id_a = Edges[fa].back();
            Edges[fa].pop_back();
        }
        
        a1 = Dominoes[id_a].first;
        b1 = Dominoes[id_a].second;
        Dominoes[id_a] = make_pair(0, 0);
    }

    int id_b = -1;
    int a2{}, b2{};

    if (Edges[fb].size()){
        id_b = Edges[fb].back();
        Edges[fb].pop_back();

        if (Dominoes[id_b] == make_pair(0, 0) && Edges[fb].size()){
            id_b = Edges[fb].back();
            Edges[fb].pop_back();
        }

        a2 = Dominoes[id_b].first;
        b2 = Dominoes[id_b].second;
        Dominoes[id_b] = make_pair(0, 0);
    }

    if (a1 == 0) id_a = -1;
    if (a2 == 0) id_b = -1;

    bool f1 = (id_a != -1 && test(!is_A, a1, b1));
    bool f2 = (id_b != -1 && test(!is_A, a2, b2));

    return f1 || f2;
}

void solve(){
    int N; cin >> N;
    Dominoes.resize(N);
    Edges.assign(N + 1, vector<int>());
    A.assign(N + 1, false);
    B.assign(N + 1, false);
    bad = false;

    for (int i = 0; i < N; i++){
        int a, b; cin >> a >> b;
        Dominoes[i] = {a, b};
        Edges[a].push_back(i);
        Edges[b].push_back(i);

        bad |= a == b;
        bad |= Edges[a].size() > 2;
        bad |= Edges[b].size() > 2;
    }

    dump(Dominoes);
    dump(Edges);

    while (Dominoes.size()){
        while (Dominoes.size() && Dominoes.back() == make_pair(0, 0)) Dominoes.pop_back();
        
        if (Dominoes.size()){
            auto [a, b] = Dominoes.back();
            Dominoes.back() = make_pair(0, 0);
            bad |= test(1, a, b);        
        }
    }

    cout << (bad ? "NO\n" : "YES\n");
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}