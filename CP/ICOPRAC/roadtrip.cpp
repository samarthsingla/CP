#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int MAX_N = 1000001, MAX_M = 1000001;
vector<int> adj[MAX_N]; bool visited[MAX_N]; int mus[MAX_N];

int dfs(int node){
    if (visited[node])return 0;
    else{
        int ans = mus[node];
        visited[node] = true;
        for (auto t : adj[node]){
            ans += dfs(t);
        }
        return ans;
    }
}
void display(vector<int> arr){
    printf("\n");
    for(int i = 0; i < arr.size(); ++i){
        printf("%d ", arr[i]);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for(int r = 0; r < MAX_N; r++) visited[r] = false;
    int t;
    cin >> t;
    for(int _ = 0; _ < t; ++_){
        //initialize data
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);
        for(int p = 0; p < m; ++p){
            //edges
            int u, v;
            scanf("%d%d", &u, &v);
            adj[u-1].push_back(v-1); adj[v-1].push_back(u-1);
        }
        for(int q = 0; q < n; ++q){
            scanf("%d", &mus[q]);
        }
        vector<int> g;
        int ng = 0;
        for(int i = 0; i < n; ++i){
            if (visited[i] == false){
                ng++;
                g.push_back(dfs(i));
            }
        }
        int u,l;
        if(k % 2 == 1){
            u = (k+1)/2;
            l = (k-1)/2;
        }
        else{
            u = k/2; l = k/2;
        }
        if(u + l <= ng){
            int ans = 0;
            sort(g.begin(), g.end());
            int v;
            for(v = 0; v < l; v++) ans += g[v];
            for(v = 0; v < u; v++) ans += g[ng-1-v];
            printf("%d\n", ans);
        }
        else{
            printf("-1\n");
        }

        //clear
        for(int s = 0; s < n; s++){
            adj[s].clear();
            visited[s] = false;
            mus[s] = 0;
            k = 0;
        }
    }
}



