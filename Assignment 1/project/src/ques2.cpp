#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(int argc, char *argv[]) {
	ios::sync_with_stdio(false);
	int n,m,counter=0;
	cin >> n >> m;
	int parent[n];
	vector<vector<int> > graph(n);
	bool visited[n];
	for(int i=0;i<n;i++) {
		visited[i] = false;
		parent[i] = -1;
	}
	for(int i = 0 ; i < m ; i++) {
		int x,y;
		cin >> x >> y;
		graph[--x].push_back(--y);
		graph[y].push_back(x);
	}
	int last,start,firstPoint;
	stack<int> s;
	while(true) {
		for(firstPoint=counter;visited[firstPoint];firstPoint++);
		counter = firstPoint + 1;
		if(firstPoint==n) break;
		s.push(firstPoint);
		while(!s.empty()) {
			int current = s.top();
			s.pop();
			if(!visited[current]) {
				visited[current] = true;
				for(int i=0;i<graph[current].size();i++) {
					if(graph[current][i]!=current and visited[graph[current][i]] and parent[current]!=graph[current][i]) {
						start = current;
						last = graph[current][i];
						cout  << current << ",";
						while(start!=last) {
							cout << start + 1 << ",";
							start = parent[start];
						}
						cout << last + 1 << "\n";
						return 0;
					}
					else if(!visited[graph[current][i]]) {
						s.push(graph[current][i]);
						parent[graph[current][i]] = current;
					}
				}
			}
		}
	}
	cout << "No Cycles\n";
	return 0;
}