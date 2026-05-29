#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
struct BIGINT{
    string num;
    BIGINT operator+(BIGINT oth){
        string a = oth.num;
        string b = num;
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int i=0,j=0;
        int n = a.size(),m=b.size();
        int c=0;
        string ans;
        while(i<n||j<m||c!=0){
            int na = (i<n?a[i]-'0':0);
            int nb = (j<m?b[j]-'0':0);
            ans.push_back(((na+nb+c)%10) +'0');
            c = (na+nb+c)/10;
            i++,j++;
        }
        reverse(ans.begin(),ans.end());
        return (BIGINT){ans};
    }
};
int main(){
    BIGINT a,b;
    cin>>a.num>>b.num;
    cout << (a+b).num << '\n';
}