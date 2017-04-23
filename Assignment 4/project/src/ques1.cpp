#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define storePair pair<ll, int>

vector<pair<int,int> > bfs(vector<vector<storePair> > graph, int start, int end) {
    cout << "";
    int vertices = graph.size();
    int parent[vertices];
    for(int i=0;i<vertices;i++) parent[i] = -1;
    bool visited[vertices];
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()) {
        int current = q.front();
        q.pop();
        for(vector<storePair>::iterator iter = graph[current].begin();iter!=graph[current].end();iter++) {
            if(!visited[(*iter).second] and (*iter).first > 0) {
                visited[(*iter).second] = true;
                q.push((*iter).second);
                parent[(*iter).second] = current;
            }
        }
    }
    vector<pair<int, int> > path;
    if(visited[end]) for(int i=end;i!=start;i=parent[i]) path.push_back(make_pair(parent[i],i));
    reverse(path.begin(),path.end());
    return path;
}

void maxFlowAlgorithm(vector<vector<storePair> >& graph, vector<vector<storePair> >& final_graph, map<int,int> locator[], int start, int end) {
    vector<pair<int,int> > path = bfs(graph,start,end);
    ll max_flow = 0;
    while(path.size() > 0) {
        ll bottleNeck = LLONG_MAX;
        for(vector<pair<int,int> >::iterator it=path.begin();it!=path.end();it++) {
            int position = (locator[(*it).first].find((*it).second))->second;
            bottleNeck = min(bottleNeck,graph[(*it).first][position].first);
        }
        for(vector<pair<int,int> >::iterator it=path.begin();it!=path.end();it++) {
            int u = (*it).first, v = (*it).second;
            int positionUV = (locator[u].find(v))->second;
            int positionVU = (locator[v].find(u))->second;
            if(final_graph[v][positionVU].first > 0) {
                if(final_graph[v][positionVU].first > bottleNeck) final_graph[v][positionVU].first -= bottleNeck; 
                else {
                    final_graph[u][positionUV].first += (bottleNeck-final_graph[v][positionVU].first);
                    final_graph[v][positionVU].first = 0;
                }
            }
            else final_graph[u][positionUV].first += bottleNeck;
            graph[u][positionUV].first -= bottleNeck;
            graph[v][positionVU].first += bottleNeck;
        }
        max_flow += bottleNeck;
        path = bfs(graph,start,end);
    }
    cout << "Max Flow: " << max_flow << "\n";
}
     
int main() {
    ios::sync_with_stdio(false);
    ll x;
    int n,m,start,end;
    cin >> n >> m;
    vector<vector<storePair> > graph(n);
    vector<vector<storePair> > final_graph(n);
    vector<vector<int> > edges(n);
    map<int,int> locator[n]; 
    while(m--) {
        int x,y;
        ll capacity;
        cin >> x >> y >> capacity;
        --x;
        --y;
        if(locator[x].find(y) != locator[x].end()) {
            int index = (locator[x].find(y))->second;
            ll otherCapacity = graph[x][index].first;
            if(otherCapacity > capacity) graph[x][index].first -= capacity;
            else {
                capacity -= otherCapacity;
                graph[x][index].first = 0;
                graph[y][index].first = capacity;
                final_graph[x][index].first = capacity;
                final_graph[y][index].first = 0;
            }
        }
        else {
            graph[x].push_back(make_pair(capacity,y));
            locator[x].insert(make_pair(y,graph[x].size()-1));
            graph[y].push_back(make_pair(0,x));
            locator[y].insert(make_pair(x,graph[y].size()-1));
            final_graph[x].push_back(make_pair(0,y));
            final_graph[y].push_back(make_pair(capacity,x));
            edges[x].push_back(y);
        }
    }
    cin >> start >> end;
    maxFlowAlgorithm(graph,final_graph,locator,--start,--end);
    for(int i=0;i<n;i++) {
        for(int j=0;j<edges[i].size();j++) {
            int u=i,v=edges[i][j];
            int position = (locator[v].find(u))->second;
            if(graph[v][position].first > 0) cout << u + 1 << " --> " << v + 1 << " : " << graph[v][position].first << "\n";
        }
    }
    return 0;
} 