#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128_t i128;
typedef pair<int,int> pii;
const int INF = 1e9+9;

void print(i128 n){
    string s;
    while(n>0){
        s.push_back(n%10+'0');
        n/=10;
    }
    reverse(s.begin(),s.end());
    cout << s << '\n';
}
i128 input(){
    string s;
    cin>>s;
    i128 n=0;
    for(char c:s){
        n*=10;
        n+=c-'0';
    }
    return n;
}
i128 k;
ll n,K;
bool chk(vector<i128> &v,i128 tar){
    i128 cnt=0;
    for(int i=1;i<=n;i++){
        if(v[i-1]>tar) continue;
        cnt+= (tar-v[i-1]+(i-1))/i;
    }
    return cnt<=k;
}
int main(){
    cin>>n>>K;
    k = K;
    vector<i128> v(n);   
    i128 L=2e18,R=-1;
    for(i128 &a:v) {
        a = input();
        L = min(L,a);
        R = max(R,a);
    }
    R+= k*n;
    i128 ans=-1;
    while(L<=R){
        i128 mid = (L+R)/2;
        if(chk(v,mid)){
            ans = mid;
            L = mid+1;
        }
        else{
            R = mid-1;
        }
    }
    print(ans);
}