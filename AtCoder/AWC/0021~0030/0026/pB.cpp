#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ll n,k;
    cin>>n>>k;
    ll ta=0,ao=0;
    for(int i=0;i<n;i++){
        ll num;
        cin>>num;
        if(ta+num<=k){
            ta+=num;
        }
        else{
            ao+=num;
        }
    }
    if(ta>ao){
        cout << "Takahashi";
    }
    else if (ta<ao){
        cout << "Aoki";
    }
    else cout << "Draw";
}