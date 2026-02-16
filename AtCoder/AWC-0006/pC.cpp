#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    ll n,m,d;
    cin>>n>>m>>d;
    ll sum=0;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        if(t-m>0){
            if((t-m)%d==0) sum+= (t-m)/d;
            else sum+= ((t-m)/d)+1;
        }
    }
    cout << sum;
}