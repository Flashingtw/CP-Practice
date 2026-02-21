#include <bits/stdc++.h>
using namespace std;
vector<string> v[505];
int n,k;

bool chk(int i,int j){
    int cnt=0;
    int idx=0,jdx=0;
    while(idx<v[i].size()&&jdx<v[j].size()){
        if(v[i][idx]==v[j][jdx]) {
            cnt++;
            idx++;
            jdx++;
        }
        else if(v[i][idx]<v[j][jdx]){
            idx++;
        }
        else{
            jdx++;
        }
    }
    return cnt>=k;
}

int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        int m;
        cin>>m;
        for(int j=0;j<m;j++){
            string s;
            cin>>s;
            v[i].push_back(s);
        }
    }
    for(int i=1;i<=n;i++) sort(v[i].begin(),v[i].end());
    int ans=0;
    for(int i=1;i<=n;i++){
        if(v[i].size()<k) continue;
        for(int j=i+1;j<=n;j++){
            if(chk(i,j)) ans++;
        }
    }
    cout << ans;
}