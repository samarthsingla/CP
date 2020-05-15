#include<bits/stdc++.h>
using namespace std;
const int MAX = 100002;
int n, v[MAX];// p[MAX]; //v = values array, p = parent array
vector<int> adj[MAX]; //adj list
int dptake[MAX], dpnotake[MAX];
bool seenTake[MAX], seenNoTake[MAX];
#define f(i, s, e) for(int i = s; i < e; i++)
int take(int i, int p); int notake(int i, int p);
int take(int i, int p){
    if(!seenTake[i]){
        int ans = 0;
        for(auto child: adj[i]){
            if(child != p){
                ans += notake(child, i);
            }
        }
        seenTake[i] = true; dptake[i] = v[i] + ans;
        return dptake[i];
    }
    else{
        return dptake[i];
    }
}
int notake(int i, int p){
    if(!seenNoTake[i]){
        int ans = 0;
        for(auto child: adj[i]){
            if(child != p){
                ans += max(notake(child, i), take(child, i));
            }
        }
        seenNoTake[i] = true; dpnotake[i] = ans;
        return ans;
    }
    else{
        return dpnotake[i];
    }
}
int main(){
    cin >> n;
    f(i, 0, MAX){
        seenTake[i] = false; seenNoTake[i] = false;
    }
    f(i, 0, n) cin >> v[i];
    f(i, 0, n-1){
        int u, v;
        cin >> u >> v; u--; v--;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    //root is the first station
    cout << max(take(0, -1), notake(0, -1));
}
