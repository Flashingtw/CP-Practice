#include <bits/stdc++.h>
using namespace std;
struct event{
    int t,type,id;
};
int main(){
    int n;
    cin>>n;
    vector<event> v;
    for(int i=0;i<n;i++){
        int t,f;
        cin>>t>>f;
        v.push_back({t,1,i});
        v.push_back({f,-1,i});
    }
    sort(v.begin(),v.end(),[&](event &a,event &b){return a.t!=b.t?a.t<b.t:a.type>b.type;});
    vector<int> ans(n);
    queue<int> q;
    int cnt=0,_max=0;
    for(event &e:v){
        if(e.type==1){
            cnt++;_max=max(_max,cnt);
            if(q.empty()) ans[e.id]=cnt;
            else{
                ans[e.id]=q.front();
                q.pop();
            }
        }
        else{
            cnt--;
            q.push(ans[e.id]);
        }
    }
    cout << _max << "\n";
    for(int i:ans) cout << i << " ";
}