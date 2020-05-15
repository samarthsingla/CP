#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, s, e) for(int i = s; i < e; i++)
const int MAX = 2002, inf = INT32_MAX;
int costs[MAX][MAX], n, dist[MAX], parent[MAX];
bool intree[MAX];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    f(i, 0, n){
        dist[i] = inf; intree[i] = false;
    }
    f(i, 0, n){
        f(j, 0, n) cin >> costs[i][j];
    }
    //city capital is node 0 //our search node indices range from 1 to n-1. Goal is to make an MST without the city capital.
    int nintree = 1, curr = 1;
    dist[curr] = 0, parent[curr] = -1;
    int ans = 0;
    while(nintree < n-1){//prims implementation
        intree[curr] = true;
        f(i, 1, n){ //this replaces adj in curr.edges because graph is complete, (every node is neighbour of curr)
            if(dist[i] > costs[curr][i]){ //doing just > and not >= ensures parent of curr doesnot get changed
                dist[i] = costs[curr][i]; parent[i] = curr;
            }
        }
        int best = inf;int next = NULL;
        f(i, 1, n){
            if(intree[i] == false && dist[i] < best && i!=curr){
                best = dist[i]; next = i;
            }
        }
        curr = next;
        ans += dist[next];
        nintree++;
    }
    cout << ans;
}

