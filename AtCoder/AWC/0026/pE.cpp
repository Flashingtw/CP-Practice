#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int n,k;

ll at(int t,vector<int> &v){
    if(t<0) return 0;
    multiset<int> ms;
    int l=0;
    ll ans=0;
    for(int r=0;r<n;r++){
        ms.insert(v[r]);
        while(*ms.rbegin()-*ms.begin()>t){
            ms.erase(ms.find(v[l]));
            l++;
        }
        ans+= r-l+1;
    }
    return ans;
}

int main(){
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cout << at(k,v)-at(k-1,v);
}