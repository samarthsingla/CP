#include <bits/stdc++.h>
using namespace std;
const int MAX = 231;
#define f(i, s, e) for(int i = s; i < e; i++)
const long inf = INT32_MAX;
int n, F;
long adj[MAX][MAX];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    f(i, 0, MAX){
        f(j, 0, MAX) adj[i][j] = inf;
    }
    cin >> n >> F;
    f(i, 0, F){
        int x, y, p;
        cin >> x >> y >> p;
        adj[x-1][y-1] = p; adj[y-1][x-1] = p;
    }
    //Floyd-Warshall
    f(k, 0, n){
        f(i, 0, n){
            f(j, 0, n){
                long t_k = adj[i][k] + adj[k][j];
                adj[i][j] = min(adj[i][j], t_k);
            }
        }
    }
    long ans = -1;
    f(i, 0, n){
        f(j, 0, n){
            if(i != j){
                ans = max(ans, adj[i][j]);
            }
        }
    }
    cout << ans;
}

