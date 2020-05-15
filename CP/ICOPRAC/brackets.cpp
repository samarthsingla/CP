#include<bits/stdc++.h>
using namespace std;
const long inf = INT32_MAX; const int MAX = 710;
#define f(i, s, e) for(int i = s; i < e; i++)
int v[MAX], b[MAX], n, k;
long dp[MAX][MAX]; bool seen[MAX][MAX];
long solve(int i, int j){
    if(i >= j) return 0;
    if(seen[i][j]) return dp[i][j];
    long ans = 0;
    f(r, i+1, j+1){
        if(b[i] + k == b[r]){
            ans = max(ans, v[i] + v[r] + solve(r+1, j) + solve(i+1, r-1));
        }
    }
    ans = max(ans, solve(i+1, j));
    seen[i][j] = true;
    dp[i][j] = ans;
    return dp[i][j];
}
int main(){
    f(i, 0, MAX){
        f(j, 0, MAX){
            seen[i][j] = false;
            dp[i][j] = 0;
        }
    }
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    f(i, 0, n) cin >> v[i];
    f(i, 0, n) cin >> b[i];
    cout << solve(0, n-1);
}
