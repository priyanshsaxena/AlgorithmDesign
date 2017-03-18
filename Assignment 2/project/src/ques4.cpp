#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmpfunc(pair<int,int> a, pair<int,int> b) {
	return a.second < b.second;
}

int main() {
	int n,sum = 0;
	cin >> n;
	vector<pair<int,int> > v;
	for(int i=0;i<n;i++) {
		int temp;
		cin >> temp;
		v.push_back(make_pair(i+1,temp));
		sum += temp;
	}
	sort(v.begin(),v.end(),cmpfunc);
	cout << "Optimal schedule is\n";
	for(vector<pair<int,int> >::iterator iter = v.begin();iter != v.end(); iter++) 
		cout << "Task " << (*iter).first << "\n";
	cout << "Minimum average completion time: " << (sum*1.0/n) << "\n";
	return 0;
}