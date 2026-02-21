#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int cnt[N],num[N];
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i:a) cnt[i]++;
    for(int i=200000;i>=1;i--) num[i]=cnt[i]+num[i+1];
    string ans="";
    int carry=0;
    for(int i=1;i<=200000||carry>0;i++){
        int cur = num[i]+carry;
        carry=cur/10;
        ans+= (cur%10)+'0';
    }
    reverse(ans.begin(),ans.end());
    bool zero=true;
    for(char c : ans){
        if(zero){
            if(c!='0'){
                cout << c;
                zero=false;
            }
        }
        else cout << c;
    }
}
