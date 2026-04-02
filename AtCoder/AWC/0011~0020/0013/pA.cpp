#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll a,b,c;
    cin>>a>>b>>c;
    if(a<b){
        cout << (b-a)*c;
    }
    else{
        cout << 0;
    }
}