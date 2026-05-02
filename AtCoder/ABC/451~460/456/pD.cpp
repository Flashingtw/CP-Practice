#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const ll mod = 998244353;
int main(){
    string s;
    cin>>s;
    int n = s.size();
    ll dpa=0,dpb=0,dpc=0;
    for(char c:s){
        if(c=='a'){
            dpa = dpa+(dpb+dpc+1)%mod;            
        }
        if(c=='b'){
            dpb = dpb+(dpa+dpc+1)%mod;
        }
        if(c=='c'){
            dpc = dpc+(dpa+dpb+1)%mod;
        }
    }
    cout << (dpa+dpb+dpc)%mod << '\n';
}