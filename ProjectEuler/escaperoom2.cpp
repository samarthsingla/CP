#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000;
#define f(i, s, e) for(int i = s; i < e; i++)
bool dp[MAX][MAX], seen[MAX][MAX];
int a[MAX][MAX];
int m, n;
class cell{
public:
    int i, j;
    cell(int x, int y){
        i = x; j = y;
    }
};
int main(){
    //1 based indexing
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> m >> n;
    f(i, 0, m){
        f(j, 0, n){
            int x; cin >> x;a[i][j] = x;
            seen[i][j] = false;
        }
    }
    queue<cell> q;
    cell first = cell(0,0);
    q.push(first);
    bool done = false;
    while(!q.empty()){
        cell curr = q.front();
        int x = a[curr.i][curr.j];
        if(x == m*n){
            done = true;
            break;
        }
        seen[curr.i][curr.j] = true;
        int ul = floor(sqrt(x));
        f(p, 1, ul+1){
            if(x % p == 0){
                int i = p-1, j = (x/p)-1;
                if(i < m && j < n){
                    if(!seen[i][j]){
                        cell newcell = cell(i,j);
                        q.push(newcell);
                    }
                }
                i = (x/p)-1; j = p-1;
                if(i < m && j < n){
                    if(!seen[i][j]){
                        cell newcell = cell(i,j);
                        q.push(newcell);
                    }
                }
            }
        }
        q.pop();
    }
    if(done)cout << "yes";
    else cout << "no";
}
