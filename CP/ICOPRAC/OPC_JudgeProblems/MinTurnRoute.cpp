#include<bits/stdc++.h>
using namespace std;
#define f(i, s, e) for(int i = s; i < e; i++)
int n, m;
vector<int> a[1000001];
int rotate(vector<int> w1, vector<int> w2, int pos1, int pos2){
    int p;
    f(i, 0, 4){
        if(w1[i] == w2[pos2]){
            p = i;
        }
    }
    return (pos1 - p) % 4;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m; //n:rows, m:cols
    f(i, 0, n){
        f(j, 0, m){
            f(i, 0, 4){

            }
        }
    }
}