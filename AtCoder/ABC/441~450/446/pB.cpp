#include <bits/stdc++.h>
using namespace std;
bool us[105];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int l;
        cin>>l;
        int d=0;
        for(int i=0;i<l;i++){
            int x;
            cin>>x;
            if(d==0&&!us[x]){
                d=x;
                us[x]=true;
            }
        }
        cout << d << "\n";
    }
}