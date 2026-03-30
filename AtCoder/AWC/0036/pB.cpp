#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    map<int,bool> mp;
    int q;
    cin>>q;
    while(q--){
        int t,x;
        cin>>t>>x;
        if(t==1){
            mp[x]=1;
        }
        else{
            if(mp.count(x)){
                cout << "Yes\n";
            }
            else{
                cout << "No\n";
            }
        }
    }
}