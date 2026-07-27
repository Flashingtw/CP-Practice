#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ll x=0;
    int q;
    cin>>q;
    while(q--){
        int type,i;
        cin>>type>>i;
        if(type==1){
            x|=(1LL<<i);
        }
        if(type==2){
            x&= ~(1LL<<i);
        }
        if(type==3){
            x^= (1LL<<i);
        }
        if(type==4){
            int j;
            cin>>j;
            if(!(((x>>i)&1)==((x>>j)&1))){
                x^= (1LL<<i);
            }
        }
        cout << x << '\n';
    }
}