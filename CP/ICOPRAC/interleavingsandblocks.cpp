//AC: https://www.codechef.com/ZCOPRAC/problems/ZCO20002
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, s, e) for(int i = s; i < e; i++)
#define MOD 100000007
ll dp[103][103][205][2]; // 0: a, 1: b
int a[102], b[102], n, m, k;
void init(){
    f(i, 0, n+2){
        f(j, 0, m+2){
            f(l, 0, k+2){
                dp[i][j][l][0] = 0;
                dp[i][j][l][1] = 0;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        cin >> n >> m >> k;
        init();
        f(i, 0, n)cin >> a[i+1];
        f(i, 0, m)cin >> b[i+1];
        dp[1][0][1][0] = 1; dp[0][1][1][1] = 1; //dp(i, j, k, v) = used i of a, j of b, made k blocks till now, last was from v(0:a, 1:b)
        //first is When one of i, j = 0
        a[0] = -1; b[0] = -1;
        f(i, 2, n+1){
            f(bm, 1, i+1){
                if(a[i] == a[i-1]) dp[i][0][bm][0] += dp[i-1][0][bm][0];
                else dp[i][0][bm][0] += dp[i-1][0][bm-1][0];
            }
        }
        f(i, 2, m+1){
            f(bm, 1, i+1){
                if(b[i] == b[i-1]) dp[0][i][bm][1] += dp[0][i-1][bm][1];
                else dp[0][i][bm][1] += dp[0][i-1][bm-1][1];
            }
        }
        f(i, 1, n+1){
            f(j, 1, m+1){
                f(bm, 1, i+j){
                    if(a[i]==a[i-1]) dp[i][j][bm][0] += dp[i-1][j][bm][0]%MOD;
                    else dp[i][j][bm][0] += dp[i-1][j][bm-1][0]%MOD;

                    if(a[i]==b[j]) dp[i][j][bm][0] += dp[i-1][j][bm][1]%MOD;
                    else dp[i][j][bm][0] += dp[i-1][j][bm-1][1]%MOD;

                    if(b[j] == b[j-1]) dp[i][j][bm][1] += dp[i][j-1][bm][1]%MOD;
                    else dp[i][j][bm][1] += dp[i][j-1][bm-1][1]%MOD;

                    if(b[j] == a[i]) dp[i][j][bm][1] += dp[i][j-1][bm][0]%MOD;
                    else dp[i][j][bm][1] += dp[i][j-1][bm-1][0]%MOD;
                    dp[i][j][bm][1] %= MOD;
                    dp[i][j][bm][0] %= MOD;
                }
            }
        }
        cout << (dp[n][m][k][0] + dp[n][m][k][1])%MOD << "\n";
    }
}
