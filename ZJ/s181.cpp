#include <bits/stdc++.h>
using namespace std;
int n,m,r,k,t;
int v[105];
int get_class(int i){
    return (i-1)/r+1;
}
vector<int> ans;
int cnt=0;
int s[10],mp[20];
void dfs(vector<int> &cur,int num){
    if(cnt>=t) return;
    if(cur.size()>=k){
        cnt++;
        if(cnt==t){
            ans=cur;
        }
        return;
    }
    for(int i=num;i<=m*r;i++){
        if(cnt>=t) return;
        if(s[v[i]]||mp[get_class(i)]>=2) continue;
        else{
            s[v[i]]++;
            mp[get_class(i)]++;
            cur.push_back(i);
            dfs(cur,i+1);

            s[v[i]]--;
            mp[get_class(i)]--;
            cur.pop_back();
        }
    }
}
int main(){
    cin>>n>>m>>r>>k>>t;
    for(int i=1;i<=m*r;i++){
        cin>>v[i];
    }
    vector<int> v;
    dfs(v,1);
    
    for(int i:ans){
        cout << i << ' ';
    }
}