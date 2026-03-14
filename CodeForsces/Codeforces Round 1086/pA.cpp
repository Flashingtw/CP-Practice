#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
bool solve(){
    int n;
    cin>>n;
    vector<int> v(n*n+1);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int num;
            cin>>num;
            v[num]++;
        }
    }
    for(int i=1;i<=n*n;i++){
        if(v[i]>n*(n-1)) return false;
    }
    return true;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        if(solve()) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
}