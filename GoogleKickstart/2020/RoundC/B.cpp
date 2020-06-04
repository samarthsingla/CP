#include <bits/stdc++.h>
using namespace std;
#define f(i, s, e) for (int i = s; i < e; i++)
#define ll long long
#define ull unsigned long long
#define aa first
#define bb second
#define vi vector<int>
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
    int t = 1; int T;
    cin >> t; T = t; 
    while (t--)
    {
        int r, c;
        cin >> r >> c;
        int a[r][c];
        bool adj[26][26];
        bool valid[26];
        memset(valid, 0, 26);
        bool vis[26];
        int inc[26];  //stores the incoming edges of nodes
        queue<int> S; // set S of all active nodes
        vi ans;       //our answer to be printed
        vi adjl[26]; //vectors containing neighbours of node i
        f(i, 0, 26) inc[i] = 0;
        f(i, 0, 26)
        {
            f(j, 0, 26)
            {
                adj[i][j] = false;
            }
        }
        f(i, 0, r)
        {
            f(j, 0, c)
            {
                char p;
                cin >> p;
                a[i][j] = int(p) - 65;
            }
        }
        int N = 0;
        f(i, 0, r - 1)
        {
            f(j, 0, c)
            {
                if (a[i + 1][j] != a[i][j])
                {
                    //add edge from bottom to top
                    if (adj[a[i + 1][j]][a[i][j]] == false)
                    {
                        inc[a[i][j]] += 1;
                        valid[a[i + 1][j]] = true;
                        valid[a[i][j]] = true;
                        adj[a[i + 1][j]][a[i][j]] = true;
                        adjl[a[i + 1][j]].push_back(a[i][j]);
                    }
                }
            }
        }
        int cnt = 0;
        f(i, 0, 26)
        {
            if (valid[i])
            {
                N++;
                if(inc[i] == 0){
                    S.push(i);
                    cnt++;
                }
                
            }
        }
        //topo sort
        while (!S.empty())
        {
            int v = S.front();
            S.pop();
            N--;
            for (int w : adjl[v])
            {
                inc[w]--;
                if (inc[w] == 0)
                {
                    S.push(w);
                }
            }
            ans.push_back(v);
        }
        cout << "Case #"<<T-t<<": ";
        if (N != 0)
        {
            //N hai 
            cout << -1 << endl;
        }
        else
        {
            for (int i : ans)
            {
                cout << char(i + 65);
            }
            cout << endl;
        }
    }
    return 0;
}
