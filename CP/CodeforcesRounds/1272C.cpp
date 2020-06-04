//Link: https://codeforces.com/problemset/problem/1272/C
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

bool isin(int a, int b[], int K){
    f(i, 0, K){
        if(b[i] == a){
            // cout << a << "  ";
            return true;
        }
    }
    return false; 
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("error.txt", "w", stderr); 
    freopen("output.txt", "w", stdout); 
    #endif
    int t = 1;// cin >> t; 
    while(t--){
        int n, k; cin>> n >> k; 
        char p[n+1]; int a[n];
        int avail[k];
        cin >> p;
        f(i, 0, n){
            a[i] = int(p[i]) - 97;
        }
        f(i, 0, k){
            char r; cin >> r; 
            avail[i] = int(r) - 97;
        }
        vi segs; 
        int i = 0; 
        int currseglen = 0; 
        while(i < n){
            if(!isin(a[i], avail, k)){
                segs.push_back(currseglen);
                currseglen = 0;
            }
            else{
                currseglen++;
            }
            i++;
        }
        segs.push_back(currseglen);
        ll ans = 0; 
        for(auto l : segs){
            ans += (ll) l*(l+1)/2;
        }
        cout << ans << endl; 
        
    }
    return 0;
}
