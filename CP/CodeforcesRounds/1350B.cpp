//Problem Name: 
//Link: https://codeforces.com/problemset/problem/1350/B
//Date: 
#include <bits/stdc++.h>
using namespace std;
#define f(i, s, e) for(int i = s; i < e; i++)
#define ll long long
#define ull unsigned long long
#define aa first
#define bb second
#define vi vector<int>
#define vec vector
#define pi pair<int, int>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("error.txt", "w", stderr); 
    freopen("output.txt", "w", stdout); 
    #endif
    int t = 1; cin >> t; 
    while(t--){
        int n; cin >> n; 
        int a[n];
        f(i, 0 , n){cin >> a[i];}
        int dp[n]; // max number of models starting at index i(compulsory to take this one at i)
        dp[n-1] = 1; 
        for(int i = n-2; i >= 0; i--){
            //calculate dp[i]
            dp[i] = 1;
            for(int k = 2; k <= n/(i+1); k++){
                if(a[(k*(i+1)) - 1] > a[i]){
                    dp[i] = max(dp[i], 1 + dp[(k*(i+1)) - 1]);
                }
            }
        }
        int ans = 1;
        f(i, 0, n){
            ans = max(ans, dp[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
