#include<bits/stdc++.h>
using namespace std;
const int MAX = 3005;
#define f(i, s, e) for(int i = s; i < e; i++)
#define aa first
#define bb second
#define ll long long
pair<ll, int> a[MAX];
int n, l;
bool possible(int diff){
    int dp[n];
    f(i, 0, n){
        dp[i] = 1;
    }
    f(i, 1, n){
        f(j, 0, i){
            if(abs(a[i].bb - a[j].bb) >= diff){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        if(dp[i] >= l){
            return true;
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--){
        cin >> n >> l;
        f(i, 0, n){
            ll q; cin >> q;
            a[i] = make_pair(q, i);
        }
        sort(a, a+n);
        int low = 0, high = n-1;
        f(i, 0, n){
            f(j, i+1, n){
                if(a[i].aa == a[j].aa){
                    low = max(low, abs(a[i].bb - a[j].bb));
                }
            }
        }
        while(low < high){
            int m = (int) ((low+high+1)/2);
            if(possible(m)) low = m;
            else high = m-1;
        }
        cout << low << endl;
    }
}

