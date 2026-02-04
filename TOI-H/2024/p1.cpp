#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,d;
ll reverse(ll num){
    ll sum=0;
    for(int i=1;i<=d;i++){
        sum*=10;
        sum+=num%10;
        num/=10;
    }
    return sum;
}
string numtostr(ll num){
    string res="";
    for(int i=1;i<=d;i++){
        res+=(num%10)+'0';
        num/=10;
    }
    return res;
}
int main(){
    cin>>n>>d;
    set<ll> s;
    for(int i=0;i<n;i++){
        string num;
        cin>>num;
        while(num.length()<d) num='0'+num;
        s.insert(stoll(num));
        while(1){
            sort(num.begin(),num.end(),greater());
            ll big=0;
            for(int i=0;i<d;i++){
                big*=10;
                big+= num[i]-'0';
            }
            ll t = big - reverse(big);
            if(s.count(t)){
                cout << t << "\n";
                break;
            }
            else{
                s.insert(t);
                num = numtostr(t);
            }
        }
        s.clear();
    }
}
