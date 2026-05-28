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

const int MAXN = (1 << 16) - 1;
int n;

std::vector<std::vector<int>> adj(MAXN);
std::vector<int> ans;

void dfs(int node){
	while (!adj[node].empty()){
		int nxt = adj[node].back(); adj[node].pop_back();
		dfs(nxt);
	}
	
	ans.push_back(node & 1);
}

int main() {
	FastIO;

	std::cin >> n;
	
	if (n == 1){
		std::cout << "01" << std::endl;
		return 0;
	}
	
	int killer = ((1 << (n - 1)) - 1);
	
	for (int num = 0; num < (1 << (n - 1)); num++){
		adj[num].push_back((num << 1) & killer);
		adj[num].push_back(adj[num][0] | 1);
	}
	
	dfs(0);	
	
	for (int num = 0; num < n - 2; num++) ans.push_back(0);
	for (const int val : ans) std::cout << val;
	std::cout << std::endl;
}