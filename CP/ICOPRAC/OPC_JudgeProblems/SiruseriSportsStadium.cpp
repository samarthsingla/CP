#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000001;
#define f(i, s, e) for(int i = s; i < e; i++)
class event{
public:
    int s, e, i;
};
int n;
event e[MAX];
bool comp(event e1, event e2){
    return e1.e < e2.e;
}
int main(){
    cin >> n;
    f(i, 0, n){
        cin >> e[i].s;
        int d; cin >> d;
        e[i].e = e[i].s + d; e[i].i = i;
    }
    sort(e, e+n, comp);
//    cout << e[0].e << " " << e[1].e;
    int i = 1; int curre = e[0].e; int count = 1;
    while(i < n){
        if(e[i].s > curre){
            count++; curre = e[i].e;
            i++;
        }
        else{
            i++;
        }
    }
    cout << count;
}

