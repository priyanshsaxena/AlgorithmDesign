#include <bits/stdc++.h>

using namespace std;

vector<int> tag;
vector<pair<int, pair<int,int> > > edges;
vector<pair<int, pair<int,int> > > mst;
vector<pair<int, pair<int,int> > > squareEdges;
vector<pair<int, pair<int,int> > > squareMst;

int identifier(int node) {
	return tag[node];
}

void unite(int x, int y) {
	int root1 = tag[x], root2 = tag[y];
	tag[root2] = root1;
}

void print() {
	for(int i=0;i<mst.size();i++)
		cout << mst[i].second.first+1 << "<->" << mst[i].second.second+1 << " : " << mst[i].first << "\n";
}

int main() {
	int n,m,cnt=0;
	cin >> n >> m;
	cnt = n-1;
	for(int i=0;i<n;i++) tag.push_back(i);
	for(int i=0;i<m;i++) {
		int x,y,weight;
		cin >> x >> y >> weight;
		edges.push_back(make_pair(weight,make_pair(--x,--y)));
		squareEdges.push_back(make_pair(weight*weight,make_pair(x,y)));
	}
	sort(edges.begin(),edges.end());
	for(vector<pair<int, pair<int,int> > >::iterator iter = edges.begin(); iter != edges.end() and cnt > 0;iter++) {
		pair<int,pair<int,int> > current = *iter;
		int x = current.second.first, y = current.second.second, weight = current.first;
		if(tag[x]==tag[y]) continue;
		unite(identifier(x),identifier(y));
		mst.push_back(current);
		cnt--;
	}
	tag.clear();
	for(int i=0;i<n;i++) tag.push_back(i);
	cnt = n-1;
	sort(squareEdges.begin(),squareEdges.end());
	for(vector<pair<int, pair<int,int> > >::iterator iter = squareEdges.begin(); iter != squareEdges.end() and cnt > 0;iter++) {
		pair<int,pair<int,int> > current = *iter;
		int x = current.second.first, y = current.second.second, weight = current.first;
		if(tag[x]==tag[y]) continue;
		unite(identifier(x),identifier(y));
		squareMst.push_back(current);
		cnt--;
	}
	if(mst.size()!=squareMst.size()) cout << "Different MSTs.\n";
	else {
		for(int i=0;i<squareMst.size();i++) {
			if(squareMst[i].second!=mst[i].second) {
				cout << "Different MSTs.\n";
				return 0;
			}
		}
		cout << "Same MST.\n";
	}
	return 0;
}