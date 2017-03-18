#include <bits/stdc++.h>

using namespace std;

bool isCyclic(int node, bool visited[], bool recStack[],vector<vector<int> > graph) {
    if(!visited[node]) {
        visited[node] = true;
        recStack[node] = true;
        for(int i = 0; i<graph[node].size(); ++i) {
            if (!visited[graph[node][i]] and isCyclic(graph[node][i], visited, recStack,graph)) return true;
            else if (recStack[graph[node][i]]) return true;
        }
    }
    recStack[node] = false;
    return false;
}

int main() {
	int n,m,num;
	cin >> n >> m;
	vector<vector<int> > matrix(n,vector<int>(m));
	vector<pair<int,int > > edges;
	vector<vector<int> > graph(n);
	for(int i=0;i<m;i++) {
		int x,y;
		cin >> x >> y;
		edges.push_back(make_pair(--x,--y));
	}
	cin >> num;
	for(int i=0;i<num;i++) {
		int temp,x,y;
		cin >> temp;
		x = edges[--temp].first;
		y = edges[temp].second;
		matrix[x][i] = -1;
		matrix[y][i] = 1;
		graph[x].push_back(y);
	}
	m = num;
	for(int i=0;i<m-1;i++) {
		for(int k=i+1;k<n;k++) {
			if (abs(matrix[i][i])<abs(matrix[k][i]))
                for (int j=0;j<m;j++) {
                    int temp=matrix[i][j];
                    matrix[i][j]=matrix[k][j];
                    matrix[k][j]=temp;
                }
		}
		for(int k=i+1;k<m;k++) {
			if(matrix[i][i]) {
				int factor = matrix[i][k]/matrix[i][i];
				for(int j=0;j<n;j++) matrix[j][k]-=factor*matrix[j][i];
			}
		}
	}
	for(int i=0;i<m;i++) {
		int counter = 0;
		for(int j=0;j<n;j++) if(matrix[j][i]==0) counter++;
		if(counter==n) {
			cout << "Dependent vectors. DirecStackted cycle may or may not be present.\n";
			return 0;
		}
	}
	cout << "Independent vectors. No direcStackted cycles can be present.\nLooking for cycles in matrix now....\n";
	bool visited[n],recStackStack[n];
	for(int i=0;i<n;i++) {
		visited[i] = false;
		recStackStack[i] = false;
	}
	for(int i=0;i<n;i++) {
        if (isCyclic(i,visited,recStackStack,graph)) {
        	cout<<"Cycle found. Theorem Disproved. :(\n";
        	return 0;
        }
    }
	cout << "No cycles detected. Hence verified. :)\n";
	return 0;}