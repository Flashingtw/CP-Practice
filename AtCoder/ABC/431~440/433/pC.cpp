#include <bits/stdc++.h>
using namespace std;
int main(){
    string n;
    cin>>n;
    char c=n[0],lastc='0';
    int cnt=1,lastnum=0,ans=0;
    for(int i=1;i<=n.size();i++){
        if(n[i]!=c){
            if(n[i-1]-1==lastc){
                ans+=min(lastnum,cnt);
            }
            if(i<n.size()){
                lastnum=cnt;
                lastc=c;
                cnt=1;
                c=n[i];
            }
        }
        else{
            cnt++;
        }
    }
    cout << ans;
}