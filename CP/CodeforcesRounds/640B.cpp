// Problem Name: Same Parity Summands
//Date: 13/5/2020
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
        if (k <= n)
        {
            if (n % 2 == 0)
            {
                if (k % 2 == 0)
                {
                    cout << "YES" << endl;
                    f(i, 0, k - 1)
                    {
                        cout << 1 << " ";
                    }
                    cout << n - k + 1 << endl;
                }
                else
                {
                    if (n - 2 >= (k - 1) * 2)
                    {
                        cout << "YES" << endl;
                        f(i, 0, k - 1)
                        {
                            cout << 2 << ' ';
                        }
                        cout << n - 2 * (k - 1) << endl;
                    }
                    else
                    {
                        cout << "NO" << endl;
                    }
                }
            }
            else
            {
                if (k % 2 == 0)
                {
                    cout << "NO" << endl;
                }
                else
                {
                    cout << "YES" << endl;
                    f(i, 0, k - 1)
                    {
                        cout << 1 << " ";
                    }
                    cout << n - k + 1 << endl;
                }
            }
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
