#include <bits/stdc++.h>
using namespace std;
int v[25];

vector<pair<int,int>> ans;

void hanoi(int u,int to){
    if(u==0) return;
    int from = v[u]; //u從哪來
    if(from==to){
        hanoi(u-1,to);
    }
    else{
        int oth = 3-from-to;
        hanoi(u-1,oth);
        ans.push_back({from,to});
        v[u]=to;
        hanoi(u-1,to);
    }
}

int main(){
    int m;
    cin>>m;
    for(int x=0;x<3;x++){
        int k;
        cin>>k;
        for(int i=0;i<k;i++){
            int val; cin>>val;
            v[val]=x;
        }
    }
    hanoi(m,1);
    for(auto [f,t]:ans){
        char from,to;
        if(f==0) from='A';
        if(f==1) from='B';
        if(f==2) from='C';
        if(t==0) to='A';
        if(t==1) to='B';
        if(t==2) to='C';
        cout << from << ' ' << to << '\n';
    }
}