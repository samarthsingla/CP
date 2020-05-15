#include<bits/stdc++.h>
using namespace std;
const int MAX = 10001;
int n, a[MAX], dp[MAX];
#define f(i, s, e)  for(int i = s; i < e; i++)
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    f(i, 0, n){
        cin >> a[i];
    }
    dp[0] = 1;
    f(i, 0, n){
        dp[i] = 1;
        f(j, 0, i){
            if(a[i] % a[j] == 0){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int ans = dp[0];
    f(i, 0, n){
        ans = max(ans, dp[i]);
    }
    cout << ans;
}
