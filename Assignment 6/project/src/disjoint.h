#include <bits/stdc++.h>

#ifndef DISJOINT
#define DISJOINT 1

using namespace std;

#define vi vector<int>

class disjointset {
  	public:
	  	vi parent;
		vi rank;
	  	disjointset(int n);
	  	disjointset& operator=(const disjointset& copy_from);
	  	int find(int x);
	  	void merge(int x,int y);
};

disjointset::disjointset(int n) {
	parent.assign(n+1,0);
	rank.assign(n+1,0);
	for(int i=1;i<=n;i++) parent[i] = i;
}

int disjointset::find(int x) {
	if(parent[x] == x) return x;
	parent[x]=find(parent[x]);
	return parent[x];
}

void disjointset::merge(int u,int v) {
	int x = find(u);
	int y = find(v);
	if(x!=y) {
		if(rank[x]>rank[y]) parent[y]=x;
		else if(rank[y]>rank[x]) parent[x] = y;
		else {
			parent[x] = y;
			rank[y] += 1;
		}
	}
}

disjointset& disjointset::operator=(const disjointset& copy_from) {
	parent = copy_from.parent;
	rank = copy_from.rank;
}

#endif