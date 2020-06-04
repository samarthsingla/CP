//Link: https://codeforces.com/problemset/problem/1335/E1
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
        int p[26][n];
        f(i, 0, 26){
            f(j, 0, n) p[i][j] = 0;
        }
        f(i, 0, n){
            int el; cin >> el; el--;
            a[i] = el;
            if(i!=0){
                f(j, 0, 26){
                    if(j==el) p[j][i] = p[j][i-1] + 1;
                    else{
                        p[j][i] = p[j][i-1];
                    }
                }
            }
            else{
                p[el][i] = 1;
            }
        }

        int ans = 1;
        f(i, 1, n){
            f(j, 0, i-1){
                //calc best a s and b s for these i and j:
                int maxa = 1;
                int maxb = 1;
                f(el, 0, 26){
                    maxa = max(maxa, min(p[el][j] , p[el][n-1] - p[el][i-1]));
                    maxb = max(maxb, p[el][i-1] - p[el][j]);
                }
                ans = max(ans, (2 * maxa) + maxb);
            }
        }
        cout << ans << endl;
        // f(i, 0, 26){
        //     f(j, 0, n) cout << p[i][j] << ' ';
        //     cout << endl;
        // }
    }
    return 0;
}
