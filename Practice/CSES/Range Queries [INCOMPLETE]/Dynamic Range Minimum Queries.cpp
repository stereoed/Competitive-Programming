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
 
const int INF = 1e9;
const int long long INFL = 1e18;
 
struct ST{
    int sz = 1;
    std::vector<long long> arr;
 
    int clamp(int idx) {
		return std::max(0, std::min(idx, sz - 1));
	} 
 
    long long build_tree_full(int pointer){
        if (pointer >= sz - 1) return arr[pointer];
        long long child_a = build_tree_full(2 * pointer + 1);
        long long child_b = build_tree_full(2 * pointer + 2);
 
        arr[pointer] = std::min(child_a, child_b); // MERGE
        return arr[pointer];
    }
 
    void streefy(std::vector<long long>& v){
        while (sz < v.size()) sz <<= 1;
        arr.assign(2 * sz, INFL);
		
        for (int i = 0; i < v.size(); i++) arr[sz - 1 + i] = v[i];
        build_tree_full(0);
    }
    
    long long query(int l, int r) {
		return query(l, r, 0, 0, sz - 1);
	}
 
    long long query(int l, int r, int node, int node_l, int node_r) {
        if (r < node_l || l > node_r) return INFL; 
        if (l <= node_l && node_r <= r) return arr[node]; 
 
        int mid = (node_l + node_r) / 2;
        return std::min(query(l, r, 2*node + 1, node_l, mid),query(l, r, 2*node + 2, mid + 1, node_r));     
    }
 
    void update(int idx, long long val){
        idx = sz - 1 + clamp(idx);
        arr[idx] = val;
 
        while (idx > 0){
            idx = (idx - 1) / 2;
            arr[idx] = std::min(arr[2 * idx + 1], arr[2 * idx + 2]);
        }
    }
};
 
int n, q;
long long x, a, b;
 
int main() {
	FastIO;
	std::cin >> n >> q;
	std::vector<long long> arr(n);
	
	for (int i = 0; i < n; i++) std::cin >> arr[i];
		
	ST st;
	st.streefy(arr);	
	
	for (int i = 0; i < q; i++){
		std::cin >> x >> a >> b;
		if (x == 1){
			st.update(a - 1, b);
			continue;
		}
		
		std::cout << st.query(a-1, b-1) << std::endl;
	}
}