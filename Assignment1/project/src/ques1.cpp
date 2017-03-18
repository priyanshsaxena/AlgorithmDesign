#include <iostream>
#include <queue>

using namespace std;

bool cmpfunc(pair<int,int> a, pair<int,int> b) {
	return a.second > b.second;
}

int main(int argc, char *argv[]) {
	ios::sync_with_stdio(false);
	int n,temp;
	cin >> n;
	priority_queue<int> freeMen;
	int men[n+1][n+1], women[n+1][n+1];
	int proposals[n+1];
	int marriedWomen[n+1];
	for(int i=1;i<=n;i++) {
		freeMen.push(i);
		proposals[i] = 0;
		for(int j=1;j<=n;j++) cin >> men[i][j];
	}
	for(int i=1;i<=n;i++) {
		marriedWomen[i] = 0;
		for(int j=1;j<=n;j++) {
			cin >> temp;
			women[i][temp] = j;
		}
	}
	while(!freeMen.empty()) {
		int currentMan = freeMen.top();
		freeMen.pop();
		if(proposals[currentMan] < n) {
			int checkingNow = men[currentMan][++proposals[currentMan]];
			if(marriedWomen[checkingNow] == 0) marriedWomen[checkingNow] = currentMan;
			else {
				int currentHusband = marriedWomen[checkingNow];
				if(women[checkingNow][currentMan] < women[checkingNow][currentHusband]) {
					marriedWomen[checkingNow] = currentMan;
					freeMen.push(currentHusband);

				}
				else freeMen.push(currentMan);
			}
		}
	}
	for(int i=1;i<=n;i++) cout << "Woman " << i << " married to Man " << marriedWomen[i] << "\n";
	return 0;
}