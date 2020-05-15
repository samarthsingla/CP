#include<bits/stdc++.h>
using namespace std;
#define f(i, s, e) for(int i = s; i < e; i++)
const int MAX = 100001;
int n, e;
vector<int> adj[MAX];
int mdep[MAX], p[MAX], mindep[MAX], maxdep[MAX];
int gethead(int i){
    int temp = i;
    while(p[temp] != temp){
        temp = p[temp];
    }
    int head = temp;
    temp = p[i];
    while(temp != p[temp]){
        p[temp] = head;
    }
    return head;
}
void mergedeps(int i, int j){
    int pi = gethead(i), pj = gethead(j);
    if(mdep[i] > mdep[j]){
        //j -> i
        p[pj] = pi;
        mdep[pi] = mdep[pj] + mdep[pi];
        mindep[pi] = min(mindep[pi], mindep[pj]);
        maxdep[pi] = max(maxdep[pi], maxdep[pj]);
    }
    else{
        //i -> j
        p[pi] = pj;
        mdep[pj] = mdep[pj] + mdep[pi];
        mindep[pj] = min(mindep[pi], mindep[pj]);
        maxdep[pj] = max(maxdep[pi], maxdep[pj]);
    }
//    cout << mdep[pi] << " "<< mdep[pj] << endl;
//    cout << pi +1 << endl;
}
int main(){
    int t; cin >> t;
    while(t--){
        cin >> n >> e;
        int ndepartments = n-e;
        f(i, 0, n){
            mdep[i] = 1; p[i] = i; mindep[i] = i; maxdep[i] = i;
        }
        f(i, 0, e){
            int u, v;
            cin >> u >> v;
            adj[v-1].push_back(u-1); adj[u-1].push_back(v-1);
            cout << u << " " << v << "  ";
            mergedeps(u-1, v-1);
        }
        int odd = 0, even = 0;
        f(i, 0, n){
            if(p[i] = i){
                //leader!
                if(mdep[i] % 2 ==0){
                    //even
                    queue<int> q;
                    q.push(mindep[i]);
                    int score = 1;
                    int level = 2;
                    while(!q.empty()){
                        int curr = q.front();
                        for(int child : adj[curr]){
                            if(child != curr){
                                q.push(child); score += level;
                            }
                        }
                        q.pop(); level++;
                    }
                    even += score;
                }
                else{
                    queue<int> q;
                    q.push(maxdep[i]);
                    int score = 1;
                    int level = 2;
                    while(!q.empty()){
                        int curr = q.front();
                        for(int child : adj[curr]){
                            if(child != curr){
                                q.push(child); score += level;
                            }
                        }
                        q.pop(); level++;
                    }
                    odd += score;
                }
            }
        }
        cout << even << " " << odd << endl;
    }
}