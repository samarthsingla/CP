//
// Created by samarth on 06/05/20.
//Nastya and Scoreboard
//
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define f(i, s, e) for(int i = s; i < e; i++)
#define ll long long
#define ull unsigned long long
#define aa first
#define bb second
const int MAX = 2001;
bitset<7> digs[10];
string digstr[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
vector<pair<int, int>> el[MAX];
bool dp[2000][2000];
void init(){
    f(i, 0, 10){
        digs[i] = bitset<7>(digstr[i]);
    }
}
void check(bitset<7> a, int i){
    bool valid = false;
    int req[10];
    memset(req, -1, 10);
    for(int i = 9; i >= 0; --i){
        if((digs[i] & (~a)) == (digs[i] ^ a)){
            valid = true;
            req[i] = digs[i].count() - a.count();
            el[i].push_back(*(new pair<int, int>(i, req[i]))); //aa is the digit, bb is the bars required for that digit
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("error.txt", "w", stderr); 
    freopen("output.txt", "w", stdout); 
    #endif
    init();
    int N, K; cin >> N  >> K;
    f(i , 0 , N){
        string str;
        getline(cin, str); check(bitset<7>(str), i);
    }
    //check if the digit is valid in less than k repairings
    //ans = trace dp[0][K], dp[i][j]: biggest digit's index for which the whole thing is valid using j repairs and after the index i digits
    f(i, 0 ,10){
        if(i == el[N-1][i].bb)
            dp[N-1][i] = true;
        else 
            dp[N-1][i] = false;
    }
    for(int i = N-2; i >= 0; i++){
        for(int k = 0; k < K; k++){
            for(int d = 0; d < 10; d++){
                if(el[i][d].bb != -1 && el[i][d].bb <= K){
                    dp[i][k] = dp[i+1][k-el[i][d].bb]; 
                }
                else{
                    dp[i][k] = false;
                }
            }
        }
    }
    //backtracing
    string str = "";
    int left = K; 
    if(dp[0][K]){
        f(i, 0, N){
            bool done = false;
            int j = 0;
            while(!done){
                if(el[i][j].bb != -1 && el[i][j].bb <= left){
                    if(dp[i+1][left- el[i][j].bb]){
                        done = true; 
                        str += to_string(el[i][j].aa);
                        left -= el[i][j].bb; 
                    }
                }
            }

        }
        cout << str << endl; 
    }
    else{
        cout << -1 << endl; 
    }
    return 0;
}

    