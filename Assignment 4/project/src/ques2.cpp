#include <bits/stdc++.h>

using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    int n;
    int maxwt,i,j,sum = 0;
    cin >> n >> maxwt;
    vector<pair<int, int> > arr(n);
    for(i = 0; i < n ; i++) cin >> arr[i].second >> arr[i].first;
    sort(arr.begin(), arr.end());
    int K[n+1][maxwt+1];
    for(i = 0; i <= n; i++)
        for(j = 0; j <= maxwt; j++) {
            if(!i || !j) K[i][j] = 0;
            else if(arr[i-1].first <= j) K[i][j] = max(K[i-1][j], arr[i-1].second + K[i-1][j - arr[i-1].first]);
            else K[i][j] = K[i-1][j];   
        }
    cout << "Max value: " << K[n][maxwt] << "\n";
    int backtracker = maxwt;
    for(i=n;i>0;i--)
        if((K[i][backtracker]-K[i-1][backtracker-arr[i-1].first])==arr[i-1].second) { 
            cout << "Included: " << arr[i-1].second << " with weight " << arr[i-1].first << "\n"; 
            backtracker -= arr[i-1].first;
        }
    return 0;
}