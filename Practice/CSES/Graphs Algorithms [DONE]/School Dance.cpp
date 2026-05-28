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
 
const int MAXN = 1002;
int boys, girls, potential_pairs, k{0};
int source, sink;

int a, b;
 
int flow[MAXN][MAXN];
std::vector<std::vector<int>> adj(MAXN);
std::vector<std::pair<int, int>> ans;
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
			
			if (nxt == sink){
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

/*

Source -> 0
Boys 1...n
Girls n + 1....m + n + 1
Sink -> m + n + 2

*/

int main() {
	FastIO;
	std::cin >> boys >> girls >> potential_pairs;
	source = 0;
	sink = boys + girls + 1;
	
	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < MAXN; j++)
			flow[i][j] = 0;
 
	for (int i = 0; i < potential_pairs; i++){
		std::cin >> a >> b;
		b += boys;
		
		flow[source][a] = 1;
		flow[a][b] = 1;
		flow[b][sink] = 1;
		
		adj[a].push_back(b);
	}
	
	while (bfs(0)) k++;
	for (int boy = 1; boy <= boys; boy++){
		int girl = -1;
		for (const auto& tgirl : adj[boy]){
			if (flow[boy][tgirl] == 0) girl = tgirl - boys;
		}
		if (girl == -1) continue;
		ans.push_back({boy, girl});
	}
	
	
	std::cout << k << std::endl;
	for (const auto& [boy, girl] : ans){
		std::cout << boy << " " << girl << std::endl;
	}
}