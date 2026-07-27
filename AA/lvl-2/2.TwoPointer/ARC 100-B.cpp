#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 2e5+5;
ll pre[N];

ll query(int l,int r){
    return pre[r]-pre[l-1];
}

int main(){
    int n;
    cin>>n;
    vector<ll> v(n+5);
    for(int i=1;i<=n;i++){
        cin>>v[i];
        pre[i] = pre[i-1]+v[i];
    }
    int i=1,k=3;
    //[1,i],[i+1,j],[j+1,k],[k+1,n];
    ll ans=9e18;
    for(int j=2;j<n;j++){
        if(k<=j) k = j+1;
        while(i<j-1&&abs(query(1,i)-query(i+1,j))>abs(query(1,i+1)-query(i+2,j))){
            i++;
        }
        while(k<n-1&&abs(query(j+1,k)-query(k+1,n))>abs(query(j+1,k+1)-query(k+2,n))){
            k++;
        }
        ans = min(ans,max({query(1,i),query(i+1,j),query(j+1,k),query(k+1,n)})-min({query(1,i),query(i+1,j),query(j+1,k),query(k+1,n)}));
    }
    cout << ans << '\n';
}