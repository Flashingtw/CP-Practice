#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;

int main(){
    ll n,K;
    cin>>n>>K;
    vector<pii> v(n);
    for(int i=0;i<n;i++) cin>>v[i].x>>v[i].y;
    if(K==1){
        cout << "Infinity" << '\n';
        return 0;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int cnt=0;
            bool chk=1;
            for(int k=0;k<n;k++){
                ll dx1 = v[j].x-v[i].x;
                ll dy1 = v[j].y-v[i].y;

                ll dx2 = v[k].x-v[i].x;
                ll dy2 = v[k].y-v[i].y;

                if(dx1*dy2 - dy1*dx2 == 0){
                    if(k<j&&k!=i){
                        chk=0;
                        break;
                    }
                    cnt++;
                }
            }
            if(chk&&cnt>=K) ans++; 
        }
    }
    cout << ans;
}