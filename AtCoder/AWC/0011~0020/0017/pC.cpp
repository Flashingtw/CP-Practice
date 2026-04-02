#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main(){
    int n,q;
    cin>>n>>q;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];
    vector<int> cnt(n+1);
    for(int i=2;i<=n;i++){
        if(v[i]==v[i-1]) cnt[i]++;
    }
    vector<int> prefix(n+1);
    for(int i=1;i<=n;i++){
        cnt[i]=cnt[i-1]+cnt[i];
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        cout << cnt[r]-cnt[l] << '\n';
    }
}