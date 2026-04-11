#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int n;
    cin>>n;
    ll total=0;
    for(int i=0;i<n;i++){
        string s;
        ll val;
        cin>>s>>val;
        if(s=="normal"){
            total+=val;
        }
        else{
            total+= val/2;
        }
    }
    cout << total;
}