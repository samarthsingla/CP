//INOI1202
#include<bits/stdc++.h>
using namespace std;
const int MAX = 200001;
#define f(i, s, e) for(int i = s; i < e; i++)
#define f_(i, s, e) for(int i = e-1; i >= s; i--)
int n, a[MAX], a1[MAX], a2[MAX], l[MAX], r[MAX];
int main(){
    cin >> n;
    f(i, 0, n) cin >> a[i];
    f(i, 1, n+1){
        a1[i-1] = a[i-1] + i;
        a2[i-1] = a[i-1] + i - n;
    }
    l[0] = a1[0]; r[n-1] = a2[n-1];
    f(i, 1, n){
        l[i] = max(a1[i], l[i-1]);
        r[n-i-1] = max(a2[n-i-1], r[n-i]);
    }
    cout << l[n-1] << " ";//round 0
    f(i, 1, n){
        cout << (max(l[n-1-i], r[n-i]) + i) << " ";
    }
}

