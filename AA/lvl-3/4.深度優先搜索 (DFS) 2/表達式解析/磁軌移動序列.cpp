#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define F first
#define S second
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i=a;i<b;++i)

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
struct ev{
    ll f,e,d;
    // 開始, 結束, 距離
    // 循環次數, 0, 0 
};

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    stack<ev> st;
    string s;
    cin>>s;
    int n = sz(s);
    for(int i=0;i<n;i++){
        if(s[i]=='T'){
            int v = stoi(s.substr(i+1,2));
            i+=2;
            st.push({v,v,0});
        }
        else if (s[i]=='L'){
            int v = stoi(s.substr(i+1,1));
            st.push({-v,0,0});
            i++;
        }
        else if (s[i]=='E'){
            auto now = st.top();
            st.pop();
            while(st.top().f>0){
                now = {st.top().f,now.e,now.d+st.top().d+abs(st.top().e-now.f)};
                st.pop();
            }
            int lp = -st.top().f;
            st.pop();
            st.push({now.f,now.e,now.d*lp+abs(now.e-now.f)*(lp-1)});
        }
    }
    auto now = st.top();
    st.pop();
    while(!st.empty()){
        now = {st.top().f,now.e,now.d+st.top().d+abs(st.top().e-now.f)};
        st.pop();
    }
    cout << now.d << '\n';
}
/*
要再複習
*/