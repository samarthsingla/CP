//Link: https://codeforces.com/problemset/problem/1343/C
#include <bits/stdc++.h>
using namespace std;
#define f(i, s, e) for(int i = s; i < e; i++)
#define ll long long
#define ull unsigned long long
#define aa first
#define bb second
#define vi vector<int>
#define v vector
#define p pair

int sgn(int x){
    if(x >= 0){
        return 1;
    }
    else{
        return -1; 
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
    int t = 1; cin >> t; 
    while(t--){
        int n; cin >> n; 
        int a[n];
        f(i, 0, n)cin >> a[i];
        int l=0, r=1;
        int maxseg = a[0];
        long long ans = 0; 
        while (r < n){
            maxseg = max(maxseg, a[l]);
            if(sgn(a[r]) != sgn(a[l])){
                ans += maxseg; maxseg = a[r];
            }
            ++l; ++r; 
        }
        if(sgn(a[l]) != sgn(a[l-1])){
            ans += a[l];
        }
        else{
            maxseg = max(maxseg, a[l]);
            ans += maxseg; 
        }
        cout << ans << endl;
    }
    return 0;
}
