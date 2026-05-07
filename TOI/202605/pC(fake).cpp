#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,q;
    cin>>n>>q;
    vector<int> a(n+1),b(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i] = 500-a[i];
    }
    while(q--){
        int t;
        cin>>t;
        if(t==1){
            int k,p;
            char f;
            cin>>k>>p>>f;
            if(f=='A'){
                a[k]+=p;
            }
            else{
                b[k]+=p;
            }
        }
        else{
            int l,r;
            char f;
            cin>>l>>r>>f;
            if(f=='A'){
                int sum=0;
                for(int i=l;i<=r;i++) sum+=a[i];
                int d = sum/(r-l+1);
                int cnt=0;
                for(int i=l;i<=r;i++){
                    if(a[i]>d){
                        cnt++;
                    }
                }
                cout << cnt << '\n';
            }
            else{
                int sum=0;
                for(int i=l;i<=r;i++) sum+=b[i];
                int d = sum/(r-l+1);
                int cnt=0;
                for(int i=l;i<=r;i++){
                    if(b[i]>d){
                        cnt++;
                    }
                }
                cout << cnt << '\n';
            }
        }
    }
}