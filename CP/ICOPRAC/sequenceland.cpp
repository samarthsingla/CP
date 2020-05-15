#include<bits/stdc++.h>
using namespace std;
#define f(i, s, e) for(int i = s; i < e; i++)
const int MAX = 301;
int n, k;
unordered_set<int> c[MAX]; int l[MAX];
vector<int> adj[MAX], id[MAX];
bool vis[MAX];
bool check(int c1, int c2){
    int count = 0;
    int i = 0;
    if(l[c1] > l[c2]){
        for(auto num : id[c2]){
            if(c[c1].count(num) > 0){
                count++;
            }
            if(count >= k){
                return true;
            }
        }
    }
    else{
        for(auto num : id[c1]){
            if(c[c2].count(num) > 0){
                count++;
            }
            if(count >= k){
                return true;
            }
        }
    }
    return false;
}
int dfs(int i){
    vis[i] = true;
    int count = 1;
    for(int child : adj[i]){
        if(!vis[child]) {
            count += dfs(child);
        }
    }
    return count;
}
int main() {
    cin >> n >> k;
    f(i, 0, MAX){
        vis[i] = false;
    }
    f(i, 0, n){
        int p; cin >> p; l[i] = p;
        f(j, 0, p){
            int num; cin >> num;
            c[i].insert(num);
            id[i].push_back(num);
        }
    }
    f(i, 0, n-1){
        f(j, i+1, n){
            if(check(i, j)){
                adj[i].push_back(j); adj[j].push_back(i);
            }
        }
    }
    cout << dfs(0);
}

