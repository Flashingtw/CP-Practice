#include <bits/stdc++.h>
using namespace std;
int cnt[15];
int a[30],b[30];
int n;
int ans;
void rec(int idx){
    if(idx>=n) {
        ans++;
        return;
    }
    for(int i=0;i<n;i++){
        if(cnt[i]||a[i+idx]||b[i-idx+15]) continue;
        cnt[i]++;
        a[i+idx]++;
        b[i-idx+15]++;
        rec(idx+1);
        cnt[i]--;
        a[i+idx]--;
        b[i-idx+15]--;
    }
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        ans=0;
        rec(0);
        cout << ans << '\n';
    }
}