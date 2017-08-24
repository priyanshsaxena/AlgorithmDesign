#include <bits/stdc++.h>
#include "simplex_1.h"

using namespace std;

int main() {
	int n,m,s,t;
	cin >> n >> m >> s >> t;
	vector<pair<int,int> > edges;
	map<pair<int,int>,int> hash;
	edges.push_back(make_pair(0,0));
	vector<int> outgoing[n+4];
	vector<int> incoming[n+4];
	double capacity[n+4];
	for(int i=1;i<=m;i++){
		int u,v;
		double w;
		cin >> u >> v >> w;
		hash.insert(make_pair(make_pair(u,v),i));
		outgoing[u].push_back(v);
		incoming[v].push_back(u);
		edges.push_back(make_pair(u,v));
		capacity[i] = w;
	}
	double B[1000] = {0};
	double A[1000][1000] = {{0}};
	double C[1000] = {0};
	for(int i=1;i<=m;i++) {
		A[i][i] = 1;
		B[i] = capacity[i];
	}
	int current_row = m;
	for(int i=1;i<=n;i++) {
		if(i==s or i == t) continue;
		else {
			current_row++;
			for(vector<int>::iterator it=outgoing[i].begin();it!=outgoing[i].end();it++) {
				int value = (hash.find(make_pair(i,*it)))->second;
				A[current_row][value] = 1;
				A[current_row+1][value] = -1;
			}
			for(vector<int>::iterator it=incoming[i].begin();it!=incoming[i].end();it++) {
				int value = (hash.find(make_pair(*it,i)))->second;
				A[current_row][value] = -1;
				A[current_row+1][value] = 1;
			}
			current_row++;
		}
	}
	for(vector<int>::iterator it=outgoing[s].begin();it!=outgoing[s].end();it++){
		int value = (hash.find(make_pair(s,*it)))->second;
		C[value] = -1;
	}
	Simplex object(A,B,C,current_row,m);
	object.form_augumented_matrix();
	vector<double> ans = object.solve();
	for(vector<double>::iterator it=ans.begin();it!=ans.end();it++){
		int pos = it - ans.begin() + 1;
		double value = *it;
		int u,v;
		u = edges[pos].first;
		v= edges[pos].second;
		cout << u << "->" << v << " " << value << "\n";
	}
	return 0;
}