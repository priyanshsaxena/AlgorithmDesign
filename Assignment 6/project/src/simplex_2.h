#include <bits/stdc++.h>

using namespace std;

#ifndef SIMPLEX
#define SIMPLEX 1

#define pb push_back
#define eps 1e-6

class Simplex {
 	private:
		double A[100][100];
		double B[100];
		double C[100];
		double augumented[100][100]={{0.0}};
		int rows,cols;
		int m,n;
 	public:
	 	Simplex(double arr[][1000],double b[],double c[],int x,int y) {
	 		rows = x;
	 		cols = y;
	 		m = rows;
	 		n = cols;
	 		for(int i=1;i<=m;i++)
	 			for(int j=1;j<=n;j++)
	 				A[i][j]=arr[i][j];
	 		for(int i=1;i<=n;i++) C[i]=c[i]; 
	 		for(int j=1;j<=m;j++) B[j]=b[j];
	 	}
	 	void form_augumented_matrix(){
	 		for(int i=1;i<=rows;i++)
	 			for(int j=1;j<=cols;j++)
	 				augumented[i][j]=A[i][j];
	 		for(int j=1;j<=cols;j++) augumented[rows+1][j]=C[j];
	 		for(int i=1;i<=rows;i++) augumented[i][rows+cols+2]=B[i];
	 		for(int i=1;i<=rows+1;i++) augumented[i][cols+i]=1;
	 	}
	 	vector<double> solve() {
	 		while(true) {
	 			int min=0;
	 			int min_index;
	 			for(int j=1;j<=n+m+1;j++) {
	 				if(augumented[rows+1][j]<0){
	 					min=augumented[rows+1][j];
	 					min_index=j;
	 				}
	 			}
	 			if(min == 0) break;
	 			min = 1000;
	 			int pivot = 0;
	 			for(int i=1;i<=rows;i++) {
	 				if(augumented[i][min_index]>eps) {
	 					if(augumented[i][n+m+2]/augumented[i][min_index] < min) {
	 						min = augumented[i][n+m+2]/augumented[i][min_index];
	 						pivot = i;
	 					}
	 				}
	 			}
	 			if(pivot == 0) {
	 				cout<<"Unable to find pivot exiting...\n";
	 				break;
	 			}
	 			for(int i=1;i<=m+1;i++) {
	 				if(abs(augumented[i][min_index])>eps) {
		 				double factor = augumented[pivot][min_index]/augumented[i][min_index];
		 				if(i!=pivot) {
		 					for(int j=1;j<=n+m+2;j++)
		 						augumented[i][j]-=factor*augumented[pivot][j];
		 				}
	 				}
	 			}
	 			
	 		}
	 		vector<double> temp;
	 		for(int j=n+1;j<=m+n;j++) temp.pb(augumented[rows+1][j]);
	 		return temp;
	 	}
};

#endif