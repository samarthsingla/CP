#include<bits/stdc++.h>
using namespace std;
const long long inf = 1e15;
typedef long long ll;
const int MAX = 5005;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        ll dp[n+1][m+1] = {}, c[n];
        pair<ll, ll> p[m];
        dp[0][0] = 0;  //base
        for(int i = 0; i < n; i++){
            cin >> c[i];
        }
        for(int i = 0; i < m; i++) cin >> p[i].second; //second refers to pj
        for(int i = 0; i < m; i++) cin >> p[i].first; // first is tj
        for(int i = 1; i < n+1; i++) dp[i][0] = dp[i-1][0] + c[i-1]; //Sort of prefix sums
        sort(p, p+m);
        dp[0][1] = max(p[0].first, p[0].second);
        for(int i = 2; i < m + 1; i++){
            if(dp[0][i-1] < p[i-1].first){
                dp[0][i] = max(dp[0][i-1] + p[i-1].second, p[i-1].first);
            }
            else{
                dp[0][i] = inf;
            }
        }
        for(int i = 1; i < n + 1; i++){
            for(int j = 1; j < m + 1; j++) {
                ll poss1, poss2;
                if(dp[i][j-1] < p[j-1].first){
                    poss1 = max(p[j-1].first, dp[i][j-1] + p[j-1].second);
                    poss2 = dp[i-1][j] + c[i-1];
                    dp[i][j] = min(poss1, poss2);
                }
                else {
                    dp[i][j] = dp[i-1][j] + c[i-1];
                }
            }
        }
        cout << ((dp[n][m] >= inf) ? -1 : dp[n][m]) << "\n";
    }
}
