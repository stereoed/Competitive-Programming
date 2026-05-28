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

const unsigned long long INFL = 1e18;

int n, m, a, b;
unsigned long long c;

unsigned long long adj[500][500];
int prev[500];

std::vector<std::vector<int>> alt;

unsigned long long bfs(int node){
	for (int i = 0; i < n; i++) prev[i] = -1;
	prev[0] = 0;
	
	std::queue<std::pair<int, unsigned long long>> q;
	q.push({node, INFL});
	
	while (!q.empty()){
		auto [cur, flow] = q.front(); q.pop();
		
		for (const auto& nxt : alt[cur]){
			if (prev[nxt] != -1 || adj[cur][nxt] == 0) continue;
			
			prev[nxt] = cur;
			unsigned long long new_flow = std::min(flow, adj[cur][nxt]);
			
			if (nxt == n - 1){
				int ptr = nxt;
				while (ptr != 0){
					adj[ptr][prev[ptr]] += new_flow;
					adj[prev[ptr]][ptr] -= new_flow;
					ptr = prev[ptr];
				}
				return new_flow;
			}
			
			q.push({nxt, new_flow});
		}
	}
	
	return 0;
}

void solve() {
	std::cin >> n >> m;	
	alt = std::vector<std::vector<int>>(n);
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) adj[i][j] = 0;
	
	for (int i = 0; i < m; i++){
		std::cin >> a >> b >> c;
		a--; b--;
		
		alt[a].push_back(b);
		alt[b].push_back(a);
		adj[a][b] += c;
	}
	
	unsigned long long ans = 0;
	
	while (true){
		unsigned long long pushed = bfs(0);
		if (pushed == 0) break;
		ans += pushed;
	}

	std::cout << ans << std::endl;
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