#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
string l = {"{<(["};
string r = {"}>)]"};
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    string s;
    cin>>s;
    vector<char> st;
    int ans=0;
    for(char c:s){
        if(!st.empty()&&l.find(st.back())!=string::npos&&r.find(c)!=string::npos){
            if(!((char)(c-1)==st.back()||(char)(c-2)==st.back())) ans++;
            st.pop_back();
        }
        else st.push_back(c);
    }
    if(st.empty()) cout << ans << '\n';
    else cout << "Impossible" << '\n';
}