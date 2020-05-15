#include <bits/stdc++.h>
using namespace std;
int INDEX = 3;
class sq{
public:
    long x,y;//x, y: index; a, b: alpha, beta; size:size;
    double a, b, size;
    sq(long xx, long yy, double aa, double bb, double tt){
        x = xx;y =yy; a = aa; b = bb; size = tt;
    }
};
class comp{
public:
    bool operator()(sq s1, sq s2){
        return s1.size <= s2.size;
    }
};
double solve(double a, double b){
    return ((-(a+b) + sqrt(pow(a-b, 2) + 4))/2);
}
bool useful(sq s){
    if(s.x <= INDEX && s.y <= INDEX){
        return true;
    }
    return false;
}
int main(){
    priority_queue<sq, vector<sq>, comp> pq;
    long n = 0, count = 1;
    sq first = sq(0,0,1,0,solve(1,0));
    pq.push(first);
    //cout << first.size;
    while(count > 0){
        n++;
        sq curr = pq.top(); pq.pop();
        sq right = sq(curr.x+1, curr.y, curr.a + curr.size, curr.b, solve(curr.a + curr.size, curr.b));
        sq left = sq(curr.x, curr.y + 1, curr.a, curr.b + curr.size, solve(curr.a, curr.b + curr.size));
        pq.push(right); pq.push(left);
        if(useful(right)) count ++;
        if(useful(left)) count ++;
        if(useful(curr)) count--;
    }
    cout << n;
}
