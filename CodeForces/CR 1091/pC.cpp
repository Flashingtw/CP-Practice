#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
bool solve(){
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    if(gcd(n,a)!=1) return false;
    if(gcd(m,b)!=1) return false;
    if(2<gcd(n,m)){
        return false;
    }
    return true;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        if(solve()){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }    
}