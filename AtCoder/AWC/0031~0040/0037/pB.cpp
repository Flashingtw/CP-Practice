#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;

int main(){
    int L,R;
    cin>>L>>R;
    int n;
    cin>>n;
    int curl=L,curr=R;
    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        curl = max(curl,l);
        curr = min(curr,r);
        cout << max(0,curr-curl+1) << '\n'; 
    }
}