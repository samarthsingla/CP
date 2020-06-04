// Problem Name: Sum of Round Numbers
//Date: 13/5/2020
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
        int count = 0;
        vector<int> digs;
        int power = 0; 
        while(n > 0){
            int dig = n % 10; 
            n = (int) n/10;
            if(dig != 0){
                digs.push_back(dig * pow(10, power)); 
                count++;
            }
            power += 1; 
        }
        cout << count << endl;
        for(int i: digs){  
            cout << i << " ";
        }
        cout << endl; 
    }
    return 0;
}