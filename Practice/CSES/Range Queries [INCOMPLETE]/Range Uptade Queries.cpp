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
const int long long INFL = 0;

long long merge(long long a, long long b){
	return a + b;
}

long long lz_op(long long a, long long b){
	return a + b;
}

struct LazyST{
	int len = 1;
	std::vector<long long> st, lz;
	
	long long build(int node){
		if (node >= len - 1) return st[node];
		return st[node] = merge(build(2*node + 1), build(2*node + 2));
	}
	
	void convert(std::vector<long long>& arr){
		for (; len < arr.size(); len <<= 1);
		
		st.assign(2 * len, INFL);
		lz.assign(2 * len, 0);
		
		for (int i = 0; i < arr.size(); i++) st[len - 1 + i] = arr[i];
		build(0);
	}
	
	void push(int l, int r, int node){
        if (lz[node] == 0) return;
        st[node] = lz_op(lz[node], st[node]) * (r - l + 1);
		
        if (l != r){     
            lz[2*node + 1] = lz_op(lz[node], lz[2*node + 1]);
            lz[2*node + 2] = lz_op(lz[node], lz[2*node + 2]);
        }
		
        lz[node] = 0;
    }
	
	long long query(int l, int r){ return query(l, r, 0, 0, len - 1);}
	
	long long query(int l, int r, int node, int node_l, int node_r){
		if (r < node_l || l > node_r) return INFL;
		
		push(node_l, node_r, node);
		if (l <= node_l && node_r <= r) return st[node]; 
		
		int mid = node_l + (node_r - node_l)/2;
		return merge(query(l, r, 2*node+1, node_l, mid), query(l, r, 2*node+2, mid + 1, node_r));
	}
	
	void update(int l, int r, long long val){update(l, r, val, 0, 0, len - 1);}
	
	void update(int l, int r, long long val, int node, int node_l, int node_r){
		push(node_l, node_r, node);
		if (r < node_l || l > node_r) return;
		
		if (l <= node_l && node_r <= r){
			lz[node] = lz_op(lz[node], val);
			push(node_l, node_r, node);
			return;
		}
		
		int mid = node_l + (node_r - node_l)/2;
		update(l, r, val, 2*node + 1, node_l, mid);
		update(l, r, val, 2*node + 2, mid + 1, node_r);
		
		st[node] = merge(st[2*node + 1], st[2*node + 2]);
	}
};

int n, q;
long long x, a, b, c;

int main() {
	FastIO;
	std::cin >> n >> q;
	std::vector<long long> arr(n);
	
	for (int i = 0; i < n; i++) std::cin >> arr[i];
	
	LazyST st;
	st.convert(arr);	
	
	for (int i = 0; i < q; i++){
		std::cin >> x >> a;
		if (x == 1){
			std::cin >> b >> c;
			st.update(a - 1, b - 1, c);
			
			continue;
		}
		
		std::cout << st.query(a-1, a-1) << std::endl;
	}
}