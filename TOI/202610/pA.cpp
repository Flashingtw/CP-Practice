#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define EB emplace_back
#define f first
#define s second
#define ALL(x) (x).begin(),(x).end()
#define RALL(x) (x).rbegin(),(x).rend()
#define SZ(x) (int)(x).size()
#define REP(i,a,b) for(int i=(a);i<(b);++i)
#define RREP(i,a,b) for(int i=(a);i>=(b);--i)
#define EACH(x,a) for(auto &x : a)

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
typedef pair<double,double> pdd;
typedef pair<char,int> pci;
typedef pair<int,char> pic;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

const int INF = 1e9+9;
const ll LINF = 1e18+9;
const int N = 1e3+5;
int fac[N];
void init(){
    for(int i=2;i<N;i++){
        if(fac[i]) continue;
        for(int j=i+i;j<N;j+=i){
            fac[j]=1;
        }
    }
}
struct num{
    int n;
    vector<int> a;
    void init(){
        int cur=n;
        for(int i=2;i<N;i++){
            if(fac[i]) continue;
            int cnt=0;
            while(cur%i==0){
                cur/=i;
                cnt++;
            }
            if(cnt>0){
                a.push_back(i);
                a.push_back(cnt);
            }
        }
        if(cur>1){
            a.push_back(cur);
            a.push_back(1);
        }
    };
    bool operator<(const num &oth) const{
        return a<oth.a;
    };
};
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    vector<num> a(n);
    init();
    REP(i,0,n) {
        cin>>a[i].n;
        a[i].init();
    }
    sort(a.begin(),a.end());
    //for(num i:a){
    //    for(int c:i.a){
    //        cout << c << ' ';
    //    }
    //    cout << '\n';
    //}
    
    REP(i,0,n){
        cout << a[i].n << ' ';
    }
}