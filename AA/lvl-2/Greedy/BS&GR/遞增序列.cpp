#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int n,m;
vector<int> v;

bool chk(int tar){
    int prev=0;
    for(int i:v){
        if(i+tar>=m){
            if(prev>(i+tar)%m){
                prev = max(prev,i);
            }
        }
        else{
            if(prev>i+tar){
                return 0;
            }
            else prev = max(prev,i);
        }
    }
    return 1;
}

int main(){
    cin>>n>>m;
    v.resize(n);
    for(int &i:v) cin>>i;
    int l=0,r=m-1,ans=0;
    while(l<=r){
        int mid = (l+r)/2;
        if(chk(mid)){
            ans = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }    
    }
    cout << ans << '\n';
}