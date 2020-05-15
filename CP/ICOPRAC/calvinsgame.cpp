#include<bits/stdc++.h>
using namespace std;
int a[1000001], n, k;
//init dp
int findHighest(int s, int *dp){
    dp[s] = 0;
    for(int i = s+1; i < n; i++){
        dp[i] = a[i] + max(dp[i-1], dp[max(s, i-2)]);
    }
}
int findHighestReverse(int *dp){
    dp[0] = 0;
    for(int i = 1; i < n; i++){
        dp[i] = max(a[i-1] + dp[i-1], a[max(0, i-2)] + dp[max(0, i-2)]);
    }
}
int main(){
    cin >> n >> k; k--;//convert to 0-based indexing
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int dp1[n];
    findHighest(k, dp1); //straight
    int dp2[n];
    findHighestReverse(dp2); //reverse
    int ans = dp1[k] + dp2[k];
    for(int i = k+1; i < n; i++){
        ans = max(ans, dp1[i] + dp2[i]);
    }
    cout << ans;
}

