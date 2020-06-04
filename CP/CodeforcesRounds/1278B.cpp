//Link: https://codeforces.com/problemset/problem/1278/B
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
ll si(ll i){
    return (i*i + i)/2;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("error.txt", "w", stderr); 
    freopen("output.txt", "w", stdout); 
    #endif
    ll t = 1; cin >> t; 
    while(t--){
        ll a, b; cin >> a >> b;
        ll d = abs(a-b);
        if(d == 0){
            cout << "0"<< endl;
        }
        else{
            ll i = ceil((-1 + sqrt(1 + (8*d))/2));
            if(si(i) == d) cout << i << endl;
            else{
                ll d2 = si(i) - d;
                if(d2%2 == 2){
                    cout << i << endl; 
                }
                else{
                    if((d2 + i+1)%2 == 0){
                        cout << i+1 << endl;
                    }
                    else{
                        cout << i+2 << endl;
                    }
                }
            }
            
        }
    }
    return 0;
}
