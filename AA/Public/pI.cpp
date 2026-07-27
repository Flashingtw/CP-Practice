#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+1;
int cnt[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        cnt[a]++;
    }
    int q;
    cin>>q;
    while(q--){
        int x;
        cin>>x;
        if(x>=N) cout << 0 << '\n';
        else cout << cnt[x] << '\n';
    }
}