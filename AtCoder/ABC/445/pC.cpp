#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int n;
    cin>>n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    vector<int> ans(n+1);
    for(int i=n;i>0;i--){
        if(v[i]==i){
            ans[i]=i;
        }
        else{
            ans[i] = ans[v[i]];
        }
    }
    for(int i=1;i<=n;i++){
        cout << ans[i] << ' ';
    }
}