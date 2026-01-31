#include <iostream>
#include <map>
#include <vector>
typedef long long LL;
using namespace std;
LL p;

void rec(vector<int> &v,size_t n,LL prod,map<LL,LL> &mp) {
    if (n>=v.size()) {
        mp[prod] +=1;
        return;
    }
    rec(v,n+1,prod*v[n]%p,mp);
    rec(v,n+1,prod,mp);
}

LL fast_pow(LL n,LL y) {
    if (y<=0) return 1;
    if (y&1) return n*fast_pow(n,y-1)%p;
    LL t = fast_pow(n,y/2)%p;
    return t*t%p;
}

int main() {
    int i,n;
    cin>>n>>p;
    vector<int> A,B;
    map<LL,LL> MA,MB;
    for (i=0;i<n/2;i++) {
        int num;
        cin>>num;
        A.push_back(num);
    }
    for (;i<n;i++) {
        int num;
        cin>>num;
        B.push_back(num);
    }
    rec(A,0,1,MA);//從1開始 如果沒有乘任何東西1也會算一次
    rec(B,0,1,MB);
    MA[1]--;
    MB[1]--;

    LL ans = (MA[1]+MB[1])%p;
    for (auto num : MA) {
        LL a = num.first , b = num.second;
        ans += MB[fast_pow(a,p-2)]*b%p;
    }
    cout << ans;
}