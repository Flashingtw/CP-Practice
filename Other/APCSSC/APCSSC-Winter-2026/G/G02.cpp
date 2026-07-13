#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int n,m,q;
    cin>>n>>m>>q;
    vector<int> cnt[n+1];
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        cnt[b].push_back(a);
    }
    while(q--){
        int qs;
        cin>>qs;
        if(cnt[qs].empty()) {
            cout << "\n";
            continue;
        }
        cout << cnt[qs][0];
        for(int i=1;i<cnt[qs].size();i++) cout <<" "<< cnt[qs][i];
        cout << "\n";
    }
}
