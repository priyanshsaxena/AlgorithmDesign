#include <bits/stdc++.h>

using namespace std;

int sortAndCount(vector<int>& a, int lo, int hi);
int mergeAndCount(vector<int>& a,int lo,int mid,int hi);
	  	  
int sortAndCount(vector<int>& a, int lo, int hi) {
	int cnt=0;
	if(lo<hi){
		int q = (lo+hi)/2;
		cnt += sortAndCount(a,lo,q);
		cnt += sortAndCount(a,q+1,hi);
		cnt += mergeAndCount(a,lo,q,hi);
	}
	return cnt;
}	
		
int mergeAndCount(vector<int>& a,int lo,int mid,int hi){
	int n1 = hi-lo+1;
	int p = lo;
	int q = mid+1;
	int cnt=0;
	vector<int> a1(n1);
	int k=0;
	for(int i=lo;i<hi+1;i++) {
		if(p>mid) a1[k++] = a[q++];
		else if(q>hi) a1[k++]= a[p++];
		else if(a[p]>a[q]) {
			a1[k++] = a[q++];
			cnt += mid-p+1;
		}
		else a1[k++] = a[p++];
	}
	
	for(int p=0;p<k;p++) a[lo++] = a1[p];	
	return cnt;
}

int main(){
	int n,temp;
	cin>>n;
	vector<int> v;
	srand (time(NULL));
	for(int i=0;i<n;i++) {
		//cin >> temp;
		v.push_back(rand()%n);
	}
	cout<<"Number of inversions are " << sortAndCount(v,0,n-1);
	return 0;
}
