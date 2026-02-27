#include <bits/stdc++.h>
using namespace std;
bool solve(){
    int n,m;
    cin>>n>>m;
    int v = n*m;
    vector<int> pos_x(v+1,-1),pos_y(v+1,-1);
    vector<int> x(n),y(m);
    for(int i=0;i<n;i++){
        cin>>x[i];
        if(pos_x[x[i]]!=-1) return false;
        pos_x[x[i]]=i;
    }
    for(int i=0;i<m;i++){
        cin>>y[i];
        if(pos_y[y[i]]!=-1) return false;
        pos_y[y[i]]=i;
    }

}