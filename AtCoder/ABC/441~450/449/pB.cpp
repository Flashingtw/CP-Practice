#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int h,w,q;
    cin>>h>>w>>q;
    while(q--){
        int type,num;
        cin>>type>>num;
        if(type==1){
            cout << w*num << '\n';
            h-=num;
        }
        else{
            cout << h*num << '\n';
            w-=num;
        }
    }
}