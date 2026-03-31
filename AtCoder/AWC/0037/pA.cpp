#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int n;
    cin>>n;
    bool chk=0;
    int mx=0;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(a>mx){
            mx = a;
            chk=1;
        }
        else if(a==mx){
            chk=0;
        }
    }
    cout << (chk?mx:0);
}