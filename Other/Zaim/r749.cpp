#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans;
int n;
void dfs(int d,int limit,int cur){
    if(d==2){
        ans+=cur;
        return;
    }
    for(int i=0;i<=limit;i++){
        dfs(d+1,i,cur+i);
    }
}
int main(){
    cin>>n;
    dfs(0,n,0);
    cout << ans;
}