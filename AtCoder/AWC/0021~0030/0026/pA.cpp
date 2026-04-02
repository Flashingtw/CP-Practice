#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> ans;
    for(int i=1;i<=n;i++){
        int num;
        cin>>num;
        if(i%k==0){
            ans.push_back(num);
        }
    }
    for(int i:ans) cout << i << ' ';
}