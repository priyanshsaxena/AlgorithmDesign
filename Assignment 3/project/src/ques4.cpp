#include <bits/stdc++.h>
#define point pair<int,int>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n,x,y;
	cin >> n;
	point points[n];
	for(int i=0;i<n;i++) cin >> points[i].first >> points[i].second;
	sort(points,points+n);
 	int sumX[n],sumY[n],sumXY[n],sumXX[n],sumYY[n];
	x = points[0].first;
	y = points[0].second;
	sumX[0] = x;
	sumY[0] = y;
	sumXY[0] = x*y;
	sumXX[0] = x*x;
	sumYY[0] = y*y;
	for(int i=1;i<n;i++) {
		x = points[i].first;
		y = points[i].second;
		sumX[i] = sumX[i-1] + x;
		sumY[i] = sumY[i-1] + y;
		sumXY[i] = sumXY[i-1] + x*y;
		sumXX[i] = sumXX[i-1] + x*x;
		sumYY[i] = sumYY[i-1] + y*y;
	}
	//for(int i=0;i<n;i++) cout << sumX[i] << "," << sumY[i] << "," << sumXX[i] << "," << sumYY[i] << "," << sumXY[i] << "\n";
	for(int j=1;j<n;j++) {
		int X = sumX[j];
		int Y = sumY[j];
		int XY = sumXY[j];
		int YY = sumYY[j];
		int XX = sumXX[j];
		float a = ((j+1)*XY-X*Y)*1.0/((j+1)*XX-X*X); 
		float b = (Y-a*X)*1.0/(j+1);
		float eij = YY + a*a*XX + (j+1)*b*b + 2*(a*b*X-a*XY-b*Y); 
		//cout << a << ":" << b << "\n";
		cout << "Eij for 1 to " << j+1 << ": " << eij << "\n";
	}
	for(int i=1;i<n-1;i++) {
		for(int j=i+1;j<n;j++) {
			int X = sumX[j] - sumX[i-1];
			int Y = sumY[j] - sumY[i-1];
			int XY = sumXY[j] - sumXY[i-1];
			int YY = sumYY[j] - sumYY[i-1];
			int XX = sumXX[j] - sumXX[i-1];
			float a = ((j-i+1)*XY-X*Y)*1.0/((j-i+1)*XX-X*X); 
			float b = (Y-a*X)*1.0/(j-i+1);
			float eij = YY + a*a*XX + (j-i+1)*b*b + 2*(a*b*X-a*XY-b*Y);
			cout << "Eij for " << i+1 << " to " << j+1 << ": " << eij << "\n";
		}
	}
	return 0;
}