#include <bits/stdc++.h>

using namespace std;

static jmp_buf jmp;
bool flag = false;
set<int> answer;

set<int> vertexCover(set<int> graph, int numNodes ,vector<pair<int,int> > edges, int k) {
    if(edges.empty()) return set<int>();
    if(edges.size() > k*numNodes) {
        return graph;
    }
    pair<int,int> e = edges[0];
    edges.erase(edges.begin());
    set<int> copySet = graph;
    copySet.erase(e.first);
    vector<pair<int,int> > copyEdges;
    vector<pair<int,int> > newEdges;
    for(int i=0;i<edges.size();i++) {
        pair<int,int> temp = edges[i];
        if(temp.first!=e.first and temp.second!=e.first) newEdges.push_back(temp);
        else copyEdges.push_back(temp);
    }
    if((vertexCover(copySet,numNodes-1,newEdges,k-1)).size()<=(k-1)) {
        answer.insert(e.first);
        return answer;
    }
    else {
        copySet.insert(e.first);
        copySet.erase(e.second);
        copyEdges = vector<pair<int,int> >();
        newEdges = vector<pair<int,int> >();
        for(int i=0;i<edges.size();i++) {
            pair<int,int> temp = edges[i];
            if(temp.first!=e.second and temp.second!=e.second) newEdges.push_back(temp);
            else copyEdges.push_back(temp);
            
        }
        if((vertexCover(copySet,numNodes-1,newEdges,k-1)).size()<=(k-1)) {
            answer.insert(e.second);
            return answer;
        }
        else {
            flag = true;
            return graph;
        }
    }
}
     
int main() {
    ios::sync_with_stdio(false);
    int n,m,k;
    cin >> n >> m >> k;
    set<int> graph;
    for(int i=0;i<n;i++) graph.insert(i);
    vector<pair<int,int> > edges;
    while(m--) {
        int x,y;
        cin >> x >> y;
        edges.push_back(make_pair(--x,--y));
    }
    if(not setjmp(jmp)) {
        set<int> answer = vertexCover(graph,n,edges,k);
        if(answer.size()<=k) {
            for(set<int>::iterator it=answer.begin();it!=answer.end();it++) cout << (*it)+1 << " ";
            cout << "\n"; 
        }
        else cout << "No " << k << "-node vertex cover possible...\n";
    }
    return 0;
} 