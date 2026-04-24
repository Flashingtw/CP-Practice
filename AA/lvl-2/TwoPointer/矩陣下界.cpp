#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int n,x;
    cin>>n>>x;
    int i=1,j=n;
    int ans = 2e9;
    while(i<=n&&j>0){
        cout << "? " << i << ' ' << j << endl;
        int a;
        cin>>a;
        if(a>=x){
            ans = min(ans,a);
            j--;
        }
        else{
            i++;
        }
    }
    cout << "! " << (ans==2e9?-1:ans) << endl;
}