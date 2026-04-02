#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int n,q;
    cin>>n>>q;
    vector<ll> v(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    while(q--){
        int t;
        cin>>t;
        if(t==1){
            int a,b;
            cin>>a>>b;
            v[b]+=v[a];
            v[a]=0;
        }
        else{
            int c;
            cin>>c;
            cout << v[c] << '\n';
        }
    }
}