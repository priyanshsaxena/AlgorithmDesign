#include <bits/stdc++.h>

using namespace std;

enum state { UNSEEN, SEEN, VISITED };
     
long long maxWeightIndependentPath(int root, vector<long long> weights, vector<vector<int> > adj) {
	int n = adj.size();
	long long M_in[n],M_out[n];
	state arr[n];
	int parent[n];
	for(int i=0;i<n;i++) {
		parent[i] = -1;
		arr[i] = UNSEEN;
	}
    stack<int> toBeSeenNodes;
    toBeSeenNodes.push(root);
    arr[root] = SEEN;
    while(!toBeSeenNodes.empty()) {
    	int currentNode = toBeSeenNodes.top();
    	vector<int> currentList = adj[currentNode];
    	int cnt = 0;
    	for(vector<int>::iterator it=currentList.begin();it!=currentList.end();it++) {
			if(arr[*it]==UNSEEN) {
				toBeSeenNodes.push(*it);
				arr[*it] = SEEN;
				parent[*it] = currentNode;
			}
			else if(arr[*it]==VISITED) cnt++;
		}
		if(cnt==(adj[currentNode].size()-1) or (currentNode==root and cnt==adj[currentNode].size())) {
			arr[currentNode] = VISITED;
			toBeSeenNodes.pop();
			if(!cnt) {
				M_out[currentNode] = 0;
				M_in[currentNode] = weights[currentNode];
			}
			else {
				long long sum=0,moutSum=0;
				for(int i=0;i<adj[currentNode].size();i++) {
					if(arr[adj[currentNode][i]]==VISITED) {
						sum += max(M_in[adj[currentNode][i]],M_out[adj[currentNode][i]]);
						moutSum += M_out[adj[currentNode][i]];
					}
				}
				M_out[currentNode] = sum;
				M_in[currentNode] = weights[currentNode] + moutSum;
			}
		}
    }
    return max(M_in[root],M_in[root]);
}
     
int main() {
    ios::sync_with_stdio(false);
    int n,m,r;
    cin >> n >> m >> r;
    vector<long long> weights(n);
    vector<vector<int> > adj(n);
    for(int i=0;i<n;i++) cin >> weights[i];
    while(m--) {
        int x,y;
        cin >> x >> y;
        adj[--x].push_back(--y);
        adj[y].push_back(x);
    }
    cout << "Weight of max-weight independent set is: " << maxWeightIndependentPath(--r,weights,adj) << "\n";
    return 0;
} 