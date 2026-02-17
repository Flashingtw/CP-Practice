#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n,m;
    cin>>n>>m;
    ll mini= LONG_LONG_MAX;
    for(int i=0;i<n;i++){
        ll num;
        cin>>num;
        mini = min(mini,num);
    }
    ll sum=0;
    for(int i=0;i<m;i++){
        ll num;
        cin>>num;
        sum+=num;
    }
    cout << sum*mini;
}