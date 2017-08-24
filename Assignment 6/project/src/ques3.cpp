#include "disjoint.h"

#define INF (long long)(1000000007)

int main() {
	srand(time(NULL));
	int n,m;
	cin >> n >> m;
	vector<pair<int,int> > edges;
	for(int i=1;i<=m;i++){
		int u,v;
		cin >> u >> v;
		edges.push_back(make_pair(u,v));
	}
	disjointset final(n);
	int num_of_iteration = ceil(3*(n*(n-1)/2)*log(n));
	long long ans = INF;
	for(int counter =1;counter <= num_of_iteration;counter++) {
		disjointset d_set(n);
		int vertices = n;
		while(vertices > 2) {
			int num = rand()%m;
			int x = edges[num].first;
			int y = edges[num].second;
			if(d_set.find(x) == d_set.find(y)) 	continue;
			else {
				d_set.merge(x,y);
				vertices--;
			}
		}
		long long cross_edges = 0;
		for(vector<pair<int,int>>::iterator it = edges.begin();it!=edges.end();it++) {
			int x = (*it).first;
			int y = (*it).second;
			if(d_set.find(x) != d_set.find(y)) cross_edges++;
		}
		if(cross_edges < ans) {
			ans = cross_edges;
			final = d_set;
		}
	}
	cout << "The global min cut is " << ans << "\n";
	cout << "Elements in the partition are {";
	set<int> partition1,partition2;
	int parent1 = final.find(1);
	partition1.insert(1);
	for(int i=2;i<=n;i++) {
		if(final.find(i) == parent1) partition1.insert(i);
		else partition2.insert(i);
	}
	for(set<int>::iterator it = partition1.begin();it!= partition1.end();it++) cout << *it << " ";
	cout << "},{";
	for(set<int>::iterator it = partition2.begin();it!= partition2.end();it++) cout << *it << " ";
	cout << "}\n";
	return 0;
}