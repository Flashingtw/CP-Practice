#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
int main(){
    int n;
    cin>>n;
    vector<pii> v(n);
    for(int i=0;i<n;i++) cin>>v[i].first>>v[i].second;
    sort(v.begin(),v.end());
    ll ans=0,cur=0;
    for(auto [time,end]:v){
        cur+=time;
        ans+= end-cur;
    }
    cout << ans;
}
//....t1,t2,t3,t4....
//....c1,c2,c3,c4....
//cur
//t1-(cur+c1)+t2-(cur+c1+c2)+t3-(cur+c1+c2+c3)+t4-(cur+c1+c2+c3+c4)
//t1+t2+t3+t4 - (cur+4c1+3c2+2c3+1c4) ==> 前面的cur越小越好