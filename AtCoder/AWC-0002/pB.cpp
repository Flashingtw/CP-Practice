#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];
    long long sum=0,cnt=0;
    for(int i=0;i<m;i++){
        int num;
        cin>>num;
        if(v[num]>=k) continue;
        cnt++;
        sum+=v[num];
    }
    cout << cnt << " " << sum;
}