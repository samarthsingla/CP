#include <bits/stdc++.h>
using namespace std;
class block{
public:
    int i, j, ind;
    std::vector<int> adj;
};
block blocks[100001];
block unsor[100001];
bool vis[100001];
bool compareX(block a, block b){
    if(a.i == b.i) return a.j > b.j;
    return a.i > b.i;
}
bool compareY(block a, block b){
    if(a.j == b.j) return a.i > b.i;
    return a.j > b.j;
}
void display(vector<int> *v){
    cout << "SIZE : " << (*v).size();
    for(auto q: *v){
        cout << q << " ";
    }
}
int *dfs(int root){
    vis[root] = true;
    int nodes = 1, edges = 0;
    for(int boomer:unsor[root].adj){
        if(!vis[boomer]){
            ++edges;
            int* v = dfs(boomer);
            nodes += v[0]; edges += v[1];
        }
    }
    int *v = new int[2];
    v[0] = nodes;v[1] = edges;
    //cout << nodes << " " << edges;
    return v;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i = 0; i < 100001; i++){
        vis[i] = false;
    }
    int r, c, n;
    cin >> r >> c >> n;
    for(int i = 0; i < n; i++){
        cin >> blocks[i].i >> blocks[i].j;
        unsor[i].i = blocks[i].i; unsor[i].j = blocks[i].j;
        blocks[i].ind = i;
    }
    //sort by i
    std::sort(blocks, blocks + n, compareX);
    int i = 1;
    int prevx = blocks[0].i;
    while(i < n){
        if(blocks[i].i == prevx){
            if(abs(blocks[i].j - blocks[i-1].j) == 1){
                unsor[blocks[i].ind].adj.push_back(blocks[i-1].ind);
                unsor[blocks[i-1].ind].adj.push_back(blocks[i].ind);
            }
        }
        else{
            prevx = blocks[i].i;
        }
        i++;
    }
    //sort by j
    std::sort(blocks, blocks + n, compareY);
    i = 1;
    int prevy = blocks[0].j;
    while(i < n){
        if(blocks[i].j == prevy){
            if(abs(blocks[i].i - blocks[i-1].i) == 1){
                unsor[blocks[i].ind].adj.push_back(blocks[i-1].ind);
                unsor[blocks[i-1].ind].adj.push_back(blocks[i].ind);
            }
        }
        else{
            prevx = blocks[i].j;
        }
        i++;
    }
    //OK Boomer
    int ans = -1;
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            int *v = dfs(i);
            cout << v[0] << " " << v[1] << "\n";
            int t = (4 * v[0]) - (2 * v[1]);
            //cout <<"\n" << t << " ";
            ans = max(t, ans);
        }
        else{
            //cout <<
        }
    }
    cout << ans;
}



