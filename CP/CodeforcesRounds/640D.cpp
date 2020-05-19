// Problem Name:  Alice, Bob and Candies
// Link: https://codeforces.com/contest/1352/problem/D
//Date: 14/05/2020
#include <bits/stdc++.h>
using namespace std;
#define f(i, s, e) for (int i = s; i < e; i++)
#define ll long long
#define ull unsigned long long
#define aa first
#define bb second

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        f(i, 0, n) cin >> a[i];
        int moves = 0;
        int atotal = 0, btotal = 0, aprev = 0, bprev = 0, l = 0, r = n - 1;
        
        while (l <= r)
        {
            int athis = 0, bthis = 0;
            while (athis <= bprev && l <= r)
            {
                athis += a[l];
                l += 1;
            }
            atotal += athis;
            ++moves;
            while (bthis <= aprev && l <= r)
            {
                bthis += a[r];
                r -= 1;
            }
            btotal += bthis;
            if (l < r)++moves;
            aprev = athis;
            bprev = bthis;        }
        cout << moves << " " << atotal << " " << btotal << endl;
    }
    return 0;
}
