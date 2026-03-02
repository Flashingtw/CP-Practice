#include "lib0022.h"
#include <bits/stdc++.h>

using namespace std;
void solve(int n,int order[]){
    vector<int> in(n+1,-1);
    int cnt=0;
    stack<int> st1,st2;
    for(int i=0;i<n;i++){
        if(order[cnt]!=i+1) {
            push_train();
            st1.push(i+1);
            in[i+1]=1;
        }
        else{
            push_train();
            move_station_1_to_2();
            pop_train();
            cnt++;
        }
    }
    bool chk=false;
    for(;cnt<n;cnt++){
        int next = order[cnt];
        if(in[next]==1){
            while(st1.top()!=next){
                move_station_1_to_2();
                in[st1.top()]=2;
                st2.push(st1.top());
                st1.pop();
            }
            st1.pop();
            move_station_1_to_2();
            pop_train();
        }
        else if (in[next]==2){
            while(st2.top()!=next){
                move_station_2_to_1();
                in[st2.top()]=1;
                st1.push(st2.top());
                st2.pop();
            }
            st2.pop();
            pop_train();
        }
        else chk=true;
    }
    if(chk) no_solution();
}