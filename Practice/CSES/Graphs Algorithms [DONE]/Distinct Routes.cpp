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
 
const int MAXN = 500;
int n, m, k{0};
int a, b;
 
int flow[MAXN][MAXN];
std::vector<std::vector<int>> adj(MAXN), ans;
std::vector<int> prev(MAXN);
 
// Max flow
bool bfs(int node){
	for (int i = 0; i < MAXN; i++) prev[i] = -1;
	
	std::queue<std::pair<int, int>> q;
	q.push({node, 1e9});
	prev[node] = node;
	
	while (!q.empty()){
		auto [cur, cflow] = q.front(); q.pop();
		
		for (int nxt = 0; nxt < MAXN; nxt++){
			if (prev[nxt] != -1 || flow[cur][nxt] == 0) continue;
			prev[nxt] = cur;
			
			int new_flow = std::min(cflow, flow[cur][nxt]);
			
			if (nxt == n - 1){
				int ptr = nxt;
				while (ptr != node){
					flow[prev[ptr]][ptr] -= new_flow;
					flow[ptr][prev[ptr]] += new_flow;
					ptr = prev[ptr];
				}
				return true;
			}
			
			q.push({nxt, new_flow});
		}
	}
	
	return false;
}

int dfs(int node, std::vector<int>& temp){
	temp.push_back(node);
	if (node == n - 1) return true;
	
	for (const auto nxt : adj[node]){
		if (flow[node][nxt] != 0) continue;
		flow[node][nxt] = 1; // No se usa otra vez;
		
		if (dfs(nxt, temp)) return true;
	}
	
	return false;
}

int main() {
	FastIO;
	std::cin >> n >> m;
	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < MAXN; j++)
			flow[i][j] = 0;
 
	for (int i = 0; i < m; i++){
		std::cin >> a >> b;
		a--; b--;
		
		flow[a][b] = 1;
		adj[a].push_back(b);
	}
	
	while (bfs(0)) k++;
	
	while (true){
		std::vector<int> temp;
		if (!dfs(0, temp)) break;
		
		ans.push_back(temp);
	}
	
	std::cout << k << std::endl;
	for (const auto& v : ans){
		std::cout << v.size() << std::endl;
		for (const auto val : v){
			std::cout << val + 1 << " ";
		}
		std::cout << std::endl;
	}
}