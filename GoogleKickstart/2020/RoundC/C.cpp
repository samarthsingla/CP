// Problem Name: 
// Link: 
//Date: 
#include <bits/stdc++.h>
using namespace std;
#define f(i, s, e) for(int i = s; i < e; i++)
#define ll long long
#define ull unsigned long long
#define aa first
#define bb second

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
        int a[100000];
        f(i, 0, n) cin >> a[i];
        long pref[100000];
        pref[0] = a[0];
        f(i, 1, n){
        pref[i] = a[i] + pref[i-1];
        }
        int ans = 0; 
        f(r, 0, n){
            f(l, 0, r+1){
                int s = pref[r] - pref[l] + a[l];
                if(s > 0){
                    if(pow(floor(sqrt(s)),2) == s){
                        ans += 1;
                    }
                }
            }
        }
        cout << "Case #" << t+1 << ": " << ans; 
    }
    return 0;
}
