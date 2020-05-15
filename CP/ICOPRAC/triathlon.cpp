#include<bits/stdc++.h>
using namespace std;
typedef long lint;
#define e1 second
#define e2 first
bool comp(pair<int, int> a, pair<int, int> b){
    return (a.first > b.first);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    pair<int, int> a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i].e1;
        int t1, t2;
        cin >> t1 >> t2;
        a[i].e2 = t1 + t2;
    }
    sort(a, a+n, comp);
    int ans = -1, pref = 0;
    for(int i = 0; i < n; i++){
        pref += a[i].e1;
        ans = max(ans, pref + a[i].e2);
    }
    cout << ans;
}