#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n,m,start,end;
    cin >> n >> m;
    vector<vector<int> > graph(n);
    for(int i=0;i<m;i++) {
        int x,y;
        cin >> x >> y;
        graph[--x].push_back(--y);
        graph[y].push_back(x);
    }
    cin >> start >> end;
    int dist[n];
    for(int i=0;i<n;i++) dist[i] = -1;
    queue<int> wait;
    wait.push(--start);
    dist[start] = 0;
    while(wait.empty() == false) {
        int now = wait.front();
        wait.pop();
        for(int i=0;i<graph[now].size();i++) {
            if(dist[graph[now][i]] < 0) {
                wait.push(graph[now][i]);
                dist[graph[now][i]] = dist[now] + 1;
            }
        }
    }
    if(dist[--end] < 0) cout << "0\n";
    else cout << dist[end] << "\n";
    return 0;
}