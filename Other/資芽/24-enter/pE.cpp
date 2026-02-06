#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
int main(){
    int n;
    cin>>n;
    vector<pii> v(n);
    for(int i=0;i<n;i++) cin>>v[i].first>>v[i].second;
    sort(v.begin(),v.end());
    if(n<3){
        cout << "Yes";
        return 0;
    }
    bool chk=true;
    pii diff = {v[1].first-v[0].first,v[1].second-v[0].second};
    for(int i=1;i<n-1;i++){
        pii _diff =  {v[i+1].first-v[i].first,v[i+1].second-v[i].second};
        if(_diff.first*diff.second-_diff.second*diff.first!=0){
            chk=false;
            break;
        }
    }
    if(chk) cout << "Yes";
    else cout << "No";
}