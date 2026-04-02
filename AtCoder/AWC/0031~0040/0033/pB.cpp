#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ll n,k,l,r;
    cin>>n>>k>>l>>r;
    vector<ll> v;
    for(int i=0;i<n;i++) {
        int a;
        cin>>a;
        if(a>r){
            v.push_back(a-r);
        }
        else if (a<l){
            v.push_back(l-a);
        }
        else v.push_back(0);
    }
    sort(v.begin(),v.end());
    ll sum=0;
    for(int i=0;i<k;i++){
        sum+=v[i];
    }
    cout << sum;
}