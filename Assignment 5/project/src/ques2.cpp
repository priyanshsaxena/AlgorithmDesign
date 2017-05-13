#include <bits/stdc++.h>

using namespace std;
     
void maxSizeIndependentSet(vector<vector<int> > adj, vector<pair<int,int> > edges) {
    int n = adj.size(),u,v;
    bool visited[n];
    vector<int> independentSet;
    while(not edges.empty()) {
        for(u = 0; u < n ; u++) if(not(visited[u]) and adj[u].size() < 2) break;
        if(u == n) break;
        independentSet.push_back(u);
        int v = adj[u][0];
        adj[u].clear();
        adj[v].clear();
        for(int i=0;i<n;i++)
            for(int j=0;j<adj[i].size();j++) 
                if(adj[i][j]==u or adj[i][j]==v) adj[i].erase(adj[i].begin()+j);
        visited[u] = true;
        visited[v] = true;
        for(vector<pair<int,int> >::iterator it=edges.begin();it!=edges.end();it++) {
            pair<int,int> p = *it;
            if(p.first==u or p.first==v or p.second==u or p.second==v) {
                edges.erase(it);
                break;
            }
        }
    }
    cout << "Maximum-sized independent set is of size " << independentSet.size() << ".\n";
    if(independentSet.size() > 0) {
        cout << "The nodes in this set are: ";
        for(vector<int>::iterator it=independentSet.begin();it!=independentSet.end();it++) cout << *it + 1 << " ";
        cout << "\n";
    }
}
     
int main() {
    int n,m;
    cin >> n >> m ;
    vector<vector<int> > adj(n);
    vector<pair<int,int> > edges;
    while(m--) {
        int x,y;
        cin >> x >> y;
        adj[--x].push_back(--y);
        adj[y].push_back(x);
        edges.push_back(make_pair(x,y));
    }
    maxSizeIndependentSet(adj,edges);
    return 0;
} 