#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> v(n+2);
    v[0]=0;v[n+1]=0;
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    while(m--){
        int i;
        cin>>i;
        v[i-1]++;v[i]++;v[i+1]++;
    }
    for(int i=1;i<=n;i++) cout << v[i] << ' ';
}