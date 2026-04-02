#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int n;
    cin>>n;
    int mx=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x>mx){
            cout << i+1 << ' ';
            mx = x;
        }
    }
}