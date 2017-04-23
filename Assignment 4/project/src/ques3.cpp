#include <bits/stdc++.h>

using namespace std;

#define storePair pair<long long, int>
     
void shortestPath(int src, vector<vector<storePair> > adj) {
    priority_queue< storePair, vector <storePair>, greater<storePair> > pq;
    vector<long long> dist(adj.size(), LLONG_MAX);
    pq.push(make_pair(0, src));
    dist[src] = 0;
    while (!pq.empty()) {
       	int u = pq.top().second;
       	pq.pop();
       	vector<storePair>::iterator iter;
	    for (iter = adj[u].begin(); iter != adj[u].end(); ++iter) {
	       	int v = (*iter).second;
	       	long long weight = (*iter).first;
	       	if (dist[v] > dist[u] + weight) {
	           	dist[v] = dist[u] + weight;
	           	pq.push(make_pair(dist[v], v));
	       	}
	    }
    }
    for (int i = 0; i < adj.size(); ++i) cout << dist[i] << " ";
    cout << "\n";
}
     
int main() {
    ios::sync_with_stdio(false);
    long long x;
    int n,m,s;
    cin >> n >> m >> s;
    vector<vector<storePair> > adj(n);
    while(m--) {
        int x,y;
        long long weight;
        cin >> x >> y >> weight;
        adj[--x].push_back(make_pair(weight,--y));
        adj[y].push_back(make_pair(weight,x));
    }
    shortestPath(--s,adj);
    return 0;
} 