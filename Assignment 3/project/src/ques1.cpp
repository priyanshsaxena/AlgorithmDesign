#include <bits/stdc++.h>

using namespace std;

int computeOpt(int index,vector<pair<pair<int,int>,int> >& v, int p[]) {
	if(index==-1) return 0;
	return max(v[index].second+computeOpt(p[index],v,p), computeOpt(index-1,v,p));
}

int mComputeOpt(int index, vector<pair<pair<int,int>,int> >& v, int p[], int m[]){
	if(index==-1) return 0;
	else if(m[index]!=-1) return m[index];
	else m[index] = max(v[index].second+mComputeOpt(p[index],v,p,m), mComputeOpt(index-1,v,p,m));
	return m[index];
}

void findSolution(int index, vector<pair<pair<int,int>,int> >& v, int p[], int m[]){
	if(index == -1) return;
	else if (m[p[index]] + v[index].second >= m[index-1]) {
		if(p[index]>=0) {
			findSolution(p[index],v,p,m);
			cout << v[index].first.second << "-" << v[index].first.first << ":" << v[index].second << "\n";
		}
		else {
			while(index>=0 and v[index].second!=m[index]) index--;
			cout << v[index].first.second << "-" << v[index].first.first << ":" << v[index].second << "\n";
		}
	}
	else findSolution(index-1,v,p,m);
}

int main(int argc, char *argv[]) {
	ios::sync_with_stdio(false);
	vector<pair<pair<int,int>,int> > v;
	int n,j;
	cin>>n;
	int p[n],m[n];
	for(int i=0;i<n;i++) {
		int start, finish, weight;
		cin >> start >> finish >> weight;
		v.push_back(make_pair(make_pair(finish,start), weight));
		m[i] = -1;
	} 
	sort(v.begin(),v.end());
	p[0]=-1;
	for(int i=1;i<n;i++) {
		for(j=i-1;j>=0;j--) {
			if(v[i].first.second >= v[j].first.first) {
				p[i] = j;
				break;
			}
		}
		if(j<0) p[i]=-1;
	}
	cout << "Press 1 for Optimal Cost.\nPress 2 for Memoised Optimal Cost.\nPress 3 for solution.\nDefault is exit: ";
	int choice;
	cin >> choice;
	switch(choice) {
		case 1:
			cout << "The Optimal Cost is " << computeOpt(n-1,v,p) << "\n";
			break;
		case 2:
			cout << "The Optimal Cost is " << mComputeOpt(n-1,v,p,m) << "\n";
			break;
		case 3:
			choice = mComputeOpt(n-1,v,p,m);
			cout << "The solution contains these intervals:" << "\n";
			findSolution(n-1,v,p,m);
			break;
		default:
			cout << "Told you! Default is exit!\n";
			return 0;
	}
	return 0;
}