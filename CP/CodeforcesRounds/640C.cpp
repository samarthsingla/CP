// Problem Name: K-th Not Divisible by n
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
        int n, k;
        cin >> n >> k;
        int p = n - 1;
        int s = (int)k / p;
        int r = k % p;
        if (r == 0)
        {
            cout << (n * s) - 1 << endl;
        }
        else
        {
            cout << (n * s) + r << endl;
        }
    }
    return 0;
}
