#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
void solve(){
    int n,d;
    cin>>n>>d;
    vector<int> a(n+1),b(n+1);
    deque<pii> dq;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++){
        dq.push_back({a[i],i});
        while(b[i]>0){
            auto& [num,day] = dq.front();
            if(b[i]>num){
                b[i]-=num;
                dq.pop_front();
            }
            else{
                num-=b[i];
                b[i]=0;
            }
        }
        while(i-dq.front().second>=d) dq.pop_front();
    }
    int ans=0;
    for(auto [i,d]:dq){
        ans+=i;
    }
    cout << ans << "\n";
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
}