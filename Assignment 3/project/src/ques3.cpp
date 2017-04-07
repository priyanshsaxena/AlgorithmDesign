#include <bits/stdc++.h>
#define point pair<int,int>

using namespace std;

bool cmpfunc(point a, point b) {
	return a.second < b.second;
}

float dist(point a, point b) {
	int xdiff = a.first - b.first;
	int ydiff = a.second - b.second;
	return 1.0*sqrt(xdiff*xdiff + ydiff*ydiff);
}

double bruteForce(point p[], int size) {
	float ans = FLT_MAX;
	for(int i=0;i<size;i++)
		for(int j=i+1;j<size;j++)
			if(dist(p[i],p[j])<ans) ans = dist(p[i],p[j]);
	return ans;
}

double findClosestPair(point p[], int size) {
	if(size <= 3) return bruteForce(p,size);
	float left = findClosestPair(p,floor(size/2));
	float right = findClosestPair(p+(size/2), ceil(size/2));
	float minDist = min(left,right);
	point stripPoints[size];
	int j=0;
	for(int i=0;i<size;i++) if(dist(p[i],p[size/2]) < minDist) stripPoints[j++] = p[i];
	float minD = minDist;
    sort(stripPoints,stripPoints+j,cmpfunc);
    for (int i = 0; i < j; ++i)
        for (int k = i+1; k < j and (stripPoints[k].second-stripPoints[i].second < minD); ++k)
            if (dist(stripPoints[i],stripPoints[k]) < minD)
                minD = dist(stripPoints[i], stripPoints[k]);
    return min(minDist,minD);
}

int main() {
    ios::sync_with_stdio(false);
    int n;
	cin>>n;
	point p[n];
	for(int i=0;i<n;i++) cin >> p[i].first >> p[i].second;
	sort(p,p+n);
	if(n<=3) cout << "The shortest distance is " << bruteForce(p,n) << "\n";
	else cout << "The shortest distance is " << findClosestPair(p,n) << "\n";
	return 0;
}