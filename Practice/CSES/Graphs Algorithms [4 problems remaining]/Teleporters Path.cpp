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
int n, m; // node, edge
int a, b; // temp

std::vector<std::vector<int>> adj;
std::vector<int> ans, deg;

void dfs(int node){
	while (!adj[node].empty()){
		int nxt = adj[node].back(); adj[node].pop_back();
		dfs(nxt);
	}
	
	ans.push_back(node);
}

void solve() {
	std::cin >> n >> m;
	adj = std::vector<std::vector<int>>(n);
	deg = std::vector<int>(n);
	
	for (int i = 0; i < m; i++){
		std::cin >> a >> b; a--; b--;
		adj[a].push_back(b);
		
		deg[a]--;
		deg[b]++;
	}
	
	// Check feasability
	if (deg[0] != -1 || deg[n-1] != 1){
		std::cout << "IMPOSSIBLE" << std::endl;
		return;
	}
	
	for (int i = 1; i < n - 1; i++){
		if (deg[i] == 0) continue;
		
		std::cout << "IMPOSSIBLE" << std::endl;
		return;
	}
	
	// Build path
	dfs(0);
	
	// Out
	if (ans.size() != m + 1){		
		std::cout << "IMPOSSIBLE" << std::endl;
		return;
	}
	
	std::reverse(ans.begin(), ans.end());
	for (const int v : ans) std::cout << v + 1 << " ";
	std::cout << std::endl;
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