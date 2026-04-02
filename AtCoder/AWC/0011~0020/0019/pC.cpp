#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    sort(v.begin(),v.end());
    int cnt=1;
    for(int i=1;i<n;i++){
        if(v[i]-1!=v[i-1]) cnt++;
    }
    cout << cnt;
}