#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 2e5+5;
int diff[N];
int main(){
    int n,w,k;
    cin>>n>>w>>k;
    for(int i=0;i<k;i++){
        int l;
        cin>>l;
        diff[l]++;
        diff[l+w]--;
    }
    int cur=0;
    for(int i=1;i<=n;i++){
        cur += diff[i];
        cout << cur << ' ';
    }
}