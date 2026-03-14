#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int l,r,d,u;
    cin>>l>>r>>d>>u;
    ll ans=0;
    for(int x=l;x<=r;x++){
        int k = abs(x);
        int top = min(u,k);
        int bottom = max(d,-k);

        if(k%2==0&&top>=bottom){
            ans += (top-bottom+1);
        }

        int topL = max(d,k+1)+2e6;
        int topR = u+2e6;

        if(topL<=topR){ 
            ans += (topR)/2 - (topL-1)/2;
        }

        topL = d+2e6;
        topR = min(u,-k-1)+2e6;

        if(topL<=topR){ 
            ans += (topR)/2 - (topL-1)/2;
        }
    
    }
    cout << ans;
}