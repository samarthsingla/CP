//AC
#include<bits/stdc++.h>
using namespace std;
const int MAX = 1001;
const int inf = INT32_MAX;
#define ll long long
ll a[MAX][MAX],pref[MAX][MAX], n, m, k, dp[MAX][MAX][22], p1[MAX], p2[MAX];//n : rows, m: columns
#define f(i, s, e) for(long long i = s; i < e; i++)
void init(ll ival){
    f(i, 0, n){
        f(j, 0, m){
            f(p, 0, k+1) dp[i][j][k] = ival;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        cin >> n >> m >> k;
        f(i, 0, n){ //input
            f(j, 0, m) cin >> a[i][j];
        }
        f(i, 0, n){ //prefix sum calc
            pref[i][0] = a[i][0];
            f(j, 1, m) pref[i][j] = pref[i][j-1] + a[i][j];
        }
        //dp1, p1:
        init(-1 * inf);
        f(i, 0, n){
            f(j, 0, m){
                f(p, 0, k+1){
                    if(i==0){
                        dp[i][j][p] = pref[i][j];
                        continue;
                    }
                    if(j==0){
                        dp[i][j][p] = pref[i][j] + dp[i-1][j][p];
                        continue;
                    }
                    dp[i][j][p] = (p!=0)?(pref[i][j] + max(dp[i-1][j-1][p-1], dp[i-1][j][p])):pref[i][j] + dp[i-1][j][p];
                }
            }
        }
        p1[0] = dp[n-1][0][k];
        f(j, 1, m){
            p1[j] = dp[n-1][j][k];
        }
        //dp2, p2:
        init(inf);
        f(i, 0, n){
            f(j, 0, m){
                f(p, 0, k+1){
                    if(j==0){
                        dp[i][j][p] = 0;continue;
                    }
                    if(i==0){
                        dp[i][j][p] = pref[i][j-1];continue;
                    }
                    dp[i][j][p] = (p!=0)?(pref[i][j-1] + min(dp[i-1][j-1][p-1], dp[i-1][j][p])) :pref[i][j-1] + dp[i-1][j][p];
                }
            }
        }
        p2[0] = 0;
        f(j, 1, m){
            p2[j] = min(p2[j-1], dp[n-1][j][k]);
        }
        ll ans = -1 * inf;
        f(i, k+1, m){
            ans = max(ans, p1[i] - p2[i-k-1]);
        }
        cout << ans << endl;
    }
}


