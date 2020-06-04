//Link: https://codeforces.com/problemset/problem/1336/A
#include <bits/stdc++.h>
using namespace std;
#define f(i, s, e) for(int i = s; i < e; i++)
#define ll long long
#define ull unsigned long long
#define aa first
#define bb second
#define vi vector<int>
#define pi pair<int, int>
#define pb push_back
const int maxn = 200000;
int n, k; vi adj[maxn];
pi nodes[maxn];
bool vis[maxn]; 
bool isi[maxn];
bool mysort(pi a, pi b){
    return a.aa < b.bb;
}
int ans = 0; 
void dfs(int u){   
    for(int v : adj[u]){
        if(vis[v] == false){
            nodes[v].aa = nodes[u].aa + 1;
            vis[v]= true;
            dfs(v);  
        }
    }
}
int dfs2(int u, int c){
    vis[u]= true; 
    if(!isi[u]){
        c++; 
    }
    else{
        ans += c; 
    }
    for(int v : adj[u]){
        if(!vis[v]){
            dfs2(v,c); 
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("error.txt", "w", stderr); 
    freopen("output.txt", "w", stdout); 
    #endif
    int t = 1; //cin >> t; 
    while(t--){
        cin >> n >> k; 
        f(i, 0, n-1){
            int u, v; cin >> u >> v; 
            --u; --v; 
            adj[u].pb(v); adj[v].pb(u);
        }
        f(i, 0, n){
            vis[i] = false;
            nodes[i].aa = 0; nodes[i].bb = i; 
        }
        f(i, 0, n){
            if(vis[i] == false){
                vis[i] = true;
                dfs(i); 
            }
        }
        sort(nodes, nodes + n);
        f(i,0 ,n){
            vis[i] = false; 
        }
        f(i, 0 , n){
            cout << i+1 << ":" << nodes[i].aa << endl;
        }
        dfs2(0, 0); 
        //f(i, 0, n) cout << isi[i];
        //cout << ans << endl;

    }
    return 0;
}
