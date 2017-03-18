#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<pair<int,bool>, int> > v;
	vector<int> resources(n);
	for(int i=0;i<n;i++) {
		int start,end;
		cin >> start >> end;
		v.push_back(make_pair(make_pair(start,true),i));
		v.push_back(make_pair(make_pair(end,false),i));
	}
	sort(v.begin(),v.end());
	int resourcesUsed = 0;
	queue<int> freeResources;
	for(vector<pair<pair<int,bool>,int> >::iterator iter = v.begin();iter != v.end(); iter++) {
		pair<pair<int, bool>,int> current = *iter;
		if(current.first.second) {
			if(freeResources.empty()) freeResources.push(++resourcesUsed);
			resources[current.second] = (freeResources.front());
			freeResources.pop();
		}
		else freeResources.push(resources[current.second]);
	}
	for(int i=0;i<n;i++) cout << "Label " << i+1 << ": " << resources[i] << "\n"; 
	cout << "Number of resources used: " << resourcesUsed << "\n";
	return 0;
}