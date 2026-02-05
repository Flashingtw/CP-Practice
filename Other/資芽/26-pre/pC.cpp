#include <bits/stdc++.h>
using namespace std;
int main(){    ios::sync_with_stdio(0),cin.tie(0);
    int n,m,q;
    cin>>n>>m>>q;
    vector<string> v(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int val;
            cin>>val;
            reverse(v[val].begin(),v[val].end());
        }
        if(type==2){
            int x,t;
            cin>>x>>t;
            string temp="";
            temp+=v[x].substr(t);
            temp+=v[x].substr(0,t);
            v[x]=temp;
        }
        if(type==3){
            int x,i;
            char c;
            cin>>x>>i>>c;
            i--;
            v[x][i]=c;
        }
        if(type==4){
            int x,i,y,j;
            cin>>x>>i>>y>>j;
            i--,j--;
            v[x][i] = v[y][j];
        }
    }
    for(int i=1;i<=n;i++) cout << v[i] << "\n";
}
