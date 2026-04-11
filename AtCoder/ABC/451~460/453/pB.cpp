#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int n,x;
    cin>>n>>x;
    vector<int> v(n+1);
    for(int i=0;i<=n;i++) cin>>v[i];
    cout << 0 << ' ' << v[0] << '\n';
    int cur = v[0];
    for(int i=1;i<=n;i++){
        if(abs(v[i]-cur)>=x){
            cout << i << ' ' << v[i] << '\n';
            cur = v[i];
        }
    }
}