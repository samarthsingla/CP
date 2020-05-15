#include<bits/stdc++.h>
using namespace std;
#define f(i, s, e) for(int i = s; i < e; i++)
class Point{
public:
    float x, y;
    Point(float xx, float yy){
        x= xx; y = yy;
    }
};
vector<Point> a;
double error(int i, int j){

}
int main(){
    int n;
    cin >> n;
    float C = 30;
    double opt[n];
    vector<int> part;
    opt[0] = 0;
    f(i, 1, n){
        opt[i] = C + opt[i+1];
        f(j, 0, i){
            opt[i] = min(opt[i], C + error(j, i) + opt[j]);
        }
    }
}

