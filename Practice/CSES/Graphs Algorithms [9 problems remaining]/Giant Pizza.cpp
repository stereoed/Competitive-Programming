#pragma GCC optimize("Ofast")

#if __has_include("stdc++.h")
#include "stdc++.h"
#else
#include <bits/stdc++.h>
#endif

#ifdef LOCAL
    #if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
    #else
    #define dump(...)
    #endif
#else
    #define dump(...)
#endif

#define FastIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL)

const int MAXN = 1e5;

int n, m, id{0};
char c1, c2; 
int x1, x2, x1_other, x2_other;

int ids[2 * MAXN];

int sccs = 0;
int scc[2 * MAXN];
bool lock[2 * MAXN];
char res[MAXN];

std::vector<std::vector<int>> adj;
std::vector<int> st;

/*
* Creo que asi es el algoritmo xdd, me vi un video de como 5 minutos e
* intento recrearlo en codigo.
*/
void dfs(int node){
	st.push_back(node);
	ids[node] = id++;
	scc[node] = ids[node];
	
	for (const auto nxt : adj[node]){
		if (ids[nxt] == -1) dfs(nxt);
		if (!lock[nxt]) scc[node] = std::min(scc[node], scc[nxt]);
	}
	
	if (ids[node] == scc[node]){
		int ptr = st.back();
		do {
			ptr = st.back(); st.pop_back();
			lock[ptr] = true;
			scc[ptr] = sccs; 
		}
		while (ptr != node);
		sccs++;
	}
}

void solve() {
	std::cin >> m >> n;
	adj = std::vector<std::vector<int>>(2 * MAXN);
	
	for (int i = 0; i < 2 * MAXN; i++){
		scc[i] = -1;
		ids[i] = -1;
		if (i < MAXN) res[i] = 'x';
		lock[i] = false;
	} 

	/*
	* Acepto el input en forma de + 1 - 2 y normalizo todo a positivo sumando MAXN.
	* Creo una lista de adjacencia donde si no se cumple una condicion, entonces
	* la negacion de la otra tampoco se puede no cumplir.
	* Hago tambien la lista en reverso para encontrar el SCC.
	*/
	for (int i = 0; i < m; i++){
		std::cin >> c1 >> x1 >> c2 >> x2; x1--; x2--;
		x1_other = x1 + MAXN;
		x2_other = x2 + MAXN;
		
		if (c1 == '+') std::swap(x1, x1_other);
		if (c2 == '+') std::swap(x2, x2_other);	
		
		adj[x1_other].push_back(x2);
		adj[x2_other].push_back(x1);
	}
	
	for (int node = 0; node < n; node++){
		if (ids[node] == -1) dfs(node);
		if (ids[node + MAXN] == -1) dfs(node + MAXN);
	}
	
	/*
	* Si no cumplir una condicion implica que no puedo satisfacer el 
	* reverso de la condicion (y viceversa) entonces no hay solucion.
	*/
	for (int node = 0; node < n; node++){
		if (scc[node] == scc[node + MAXN]){
			std::cout << "IMPOSSIBLE" << std::endl;
			return;
		}
	}
	
	for (int node = 0; node < n; node++)
		std::cout << (scc[node + MAXN] < scc[node] ? '+' : '-') << " ";
}

int main() {
	FastIO;

#ifdef LOCAL
	auto start = std::chrono::high_resolution_clock::now();
	dump(start);
#endif

	int t = 1;
	//cin >> t;
	
	while (t--) {
		solve();
	}

#ifdef LOCAL
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> elapsed = end - start;
	std::cerr << "\n[Time] " << std::fixed << std::setprecision(6) << elapsed.count() << " ms\n";
#endif

	return 0;
}