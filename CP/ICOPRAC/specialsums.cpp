#include <bits/stdc++.h>
#include <iostream>
typedef long long ll;
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //input
    ll max1 = -10e16, max2 = -10e16, max3 = -10e16;
    ll n; cin >> n;
    ll a[n], b[n];
    for(ll i = 0; i < n; i++){
        cin >> a[i]; max1 = max(a[i],max1);
    }
    for(ll i = 0; i < n; i++) cin >> b[i];
    //prefsum
    ll pref[n];
    pref[0] = b[0];
    for(ll i = 1; i < n; i++) pref[i] = pref[i-1] + b[i];
    //CASEI, i < j: ssum(i,j) = Ai + Aj + prefj - prefi - bj
    ll m = a[0] -pref[0];
    for(ll i = 1; i < n; i++){
        max2 = max(max2, m + a[i] + pref[i] - b[i]);
        m = max(m, a[i]-pref[i]);
    }
    //CASEII, i > j: ssum(i,j) = (N - p[i]) + a[i] + a[j] + p[j] - b[j]
    m = a[0] + pref[0] - b[0];
    for(ll i = 1; i < n; i++){
        max3 = max(max3, m + a[i] + pref[n-1] - pref[i]);
        m = max(m, a[i] + pref[i] - b[i]);
    }
    cout << max(max(max1, max2), max3);
}
