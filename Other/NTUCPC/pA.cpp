#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> deg(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        deg[u]++,deg[v]++;
    }
    int c1=0,c2=0,c3=0,c4=0,c5=0;
    for(int i=1;i<=n;i++){
        switch(deg[i]){
            case 1:
                c1++;
                break;
            case 2:
                c2++;
                break;
            case 3:
                c3++;
                break;
            case 4:
                c4++;
                break;
            case 5:
                c5++;
                break;
        }
    }
    if(c3==2){
        cout << 'A' << '\n';
    }
    else if(c4==1){
        cout << 'B' << '\n';
    }
    else if(c1==2){
        cout << 'C' << '\n';
    }
    else if(c3==1){
        cout << 'E' << '\n';
    }
    else cout << 'D' << '\n';
}