#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    string s;
    cin>>s;
    vector<char> st;
    for(char c:s){
        if(!st.empty()&&((char)(c-1)==st.back()||(char)(c-2)==st.back())){
            st.pop_back();
        }
        else st.push_back(c);
    }
    if(st.empty()) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}