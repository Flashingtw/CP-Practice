#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> v(m+1);
    for(int i=1;i<=m;i++){
        cin>>v[i];
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        vector<int> cnt(m+1,0);
        vector<int> room; 
        for(int j=0;j<k;j++){
            int num;
            cin>>num;
            if(cnt[num]==0)room.push_back(num);
            cnt[num]++;
        }
        for(int r:room){
            if(cnt[r]<=v[r]) ans+=cnt[r];
            cnt[r]=0;
        }
    }
    cout << ans;
}