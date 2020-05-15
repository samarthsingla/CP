#include<bits/stdc++.h>
using namespace std;
long a[5001], m[5002];
long dp[5001][5001];
int sod(int p){
    int ans = 0;
    while(p>0){
        ans += p % 10;
        p = (int) p/10;
    }
    return ans;
}
//void display(int *arr, int q){
//    for(int i = 0; i < q; q++){
//        cout << arr[i] << " ";
//    }
//}
int main(){
    int n, s;
    cin >> n >> s;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    m[0] = s;
    for(int i = 1; i <= n; i++){
        m[i] = m[i-1] + pow(sod(m[i-1]), 3);
    }
    //display(m, n+1);
    dp[0][0] = m[0]*a[0]; dp[0][1] = 0;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i + 1; j++){
            dp[i][j] = max(dp[i-1][max(0,j-1)],(a[i]*m[j]) + dp[i-1][j]);
        }
    }
    long ans = dp[n-1][0];
    for(long score : dp[n-1]){
        ans = max(ans, score);
    }
    cout << ans;
}
