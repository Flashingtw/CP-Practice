#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 2e9;
struct item{
    ll p,s;
    int id;
};
int main(){
    int n,l,r,t;
    cin>>n>>l>>r>>t;
    item ans={INF,-1,INF};
    for(int i=0;i<n;i++){
        ll p,s;
        cin>>p>>s;
        if(l<=p&&p<=r&&s>=t){
            if(p<ans.p){
                ans={p,s,i+1};
            }
            else if (p==ans.p){
                if(s>ans.s){
                    ans={p,s,i+1};
                }
            }
        }
    }
    if(ans.id==2e9) cout << -1;
    else cout << ans.id;
}